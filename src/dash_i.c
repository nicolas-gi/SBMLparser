/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** dash_i.c
*/

#include <string.h> /* strcmp */
#include <stdlib.h> /* malloc */
#include <stdio.h> /* printf */

#include "sbml_parser.h"

static int handle_compartment(tag_t const *tag, tag_t const *found, char *arg)
{
    printf("List of species in %s %s\n", found->name, arg);
    int index = 0;
    int count = count_list(tag);
    char const **spec_names = malloc(sizeof(char *) * (count + 1));
    if (spec_names == NULL)
        return 84;

    tag_t const *species = lookup(tag, found->name, arg);
    while (species != NULL) {
        char const *spec_name = get_attribute(species->attribute, "name");
        if (strncmp(species->name, "species", 7) == 0)
            spec_names[index++] = spec_name;
        species = lookup(species->next, found->name, arg);
    }
    bubble_sort(spec_names, index);
    for (int i = 0; i < index; i++)
        printf("--->%s\n", spec_names[i]);
    free(spec_names);
    return 0;
}

static int handle_species(tag_t const *tag, tag_t const *found, char *arg)
{
    printf("List of reactions consuming %s %s (quantities)\n",
        found->name, arg);
    tag_t const *spec_ref = lookup(tag, found->name, arg);

    while (spec_ref != NULL) {
        char const *stoich = get_attribute(spec_ref->attribute,
            "stoichiometry");
        char const *reaction =
            get_attribute(spec_ref->parent->parent->attribute, "id");
        printf("--->%s (%s)\n", reaction, stoich);
        spec_ref = lookup(spec_ref->next, found->name, arg);
    }
    return 0;
}

static int handle_no_arg(tag_t const *tag)
{
    printf("List of species\n");
    int index = 0;
    int count = count_list(tag);
    char const **spec_names = malloc(sizeof(char *) * (count + 1));
    if (spec_names == NULL)
        return 84;

    while (tag != NULL) {
        if (tag->name != NULL && strcmp(tag->name, "species") == 0) {
            char const *spec_name = get_attribute(tag->attribute, "name");
            spec_names[index++] = spec_name;
        }
        tag = tag->next;
    }
    bubble_sort(spec_names, index);
    for (int i = 0; i < index; i++)
        printf("--->%s\n", spec_names[i]);
    free(spec_names);
    return 0;
}

int dash_i(tag_t const *tag, char **argv)
{
    if (strcmp(argv[2], "-i") == 0) {
        if (argv[3] == NULL)
            return handle_no_arg(tag);
        tag_t const *found = lookup(tag, "id", argv[3]);
        if (found == NULL)
            return handle_no_arg(tag);
        if (strcmp(found->name, "compartment") == 0)
            return handle_compartment(tag, found, argv[3]);
        if (strcmp(found->name, "species") == 0)
            return handle_species(tag, found, argv[3]);
        if (strcmp(found->name, "reaction") == 0)
            return handle_reaction(tag, found, argv[3], argv[4]);
    }
    return 0;
}
