/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** handle_reaction.c
*/

#include <stdio.h> /* printf */
#include <stddef.h> /* NULL */
#include <stdlib.h> /* malloc */
#include <string.h> /* strncmp */

#include "sbml_parser.h"

static int list_reactants(tag_t const *tag, tag_t const *reaction)
{
    int index = 0;
    int count = count_list(tag);
    char const **reactant_names = malloc(sizeof(char *) * (count + 1));
    if (reactant_names == NULL)
        return 84;

    tag_t const *reactants = lookup_parent(tag, "listOfReactants", reaction);
    tag_t const *spec_ref = lookup_parent(tag, "speciesReference", reactants);
    while (spec_ref != NULL) {
        char const *species = get_attribute(spec_ref->attribute, "species");
        if (strncmp(reaction->name, "reaction", 8) == 0)
            reactant_names[index++] = species;
        spec_ref = lookup_parent(spec_ref->next, "speciesReference",
            reactants);
    }
    bubble_sort(reactant_names, index);
    for (int i = 0; i < index; i++)
        printf("--->%s\n", reactant_names[i]);
    free(reactant_names);
    return 0;
}

static int list_products(tag_t const *tag, tag_t const *reaction)
{
    int index = 0;
    int count = count_list(tag);
    char const **product_names = malloc(sizeof(char *) * (count + 1));
    if (product_names == NULL)
        return 84;

    tag_t const *products = lookup_parent(tag, "listOfProducts", reaction);
    tag_t const *spec_ref = lookup_parent(tag, "speciesReference", products);
    while (spec_ref != NULL) {
        char const *species = get_attribute(spec_ref->attribute, "species");
        if (strncmp(reaction->name, "reaction", 8) == 0)
            product_names[index++] = species;
        spec_ref = lookup_parent(spec_ref->next, "speciesReference", products);
    }
    bubble_sort(product_names, index);
    for (int i = 0; i < index; i++)
        printf("--->%s\n", product_names[i]);
    free(product_names);
    return 0;
}

int handle_reaction(tag_t const *tag, tag_t const *found, char const *arg,
    char const *flag)
{
    if (flag != NULL && strcmp(flag, "-e") == 0)
        return reaction_equation(tag, found);
    printf("List of reactants of %s %s\n", found->name, arg);
    list_reactants(tag, found);
    printf("List of products of %s %s\n", found->name, arg);
    list_products(tag, found);
    return 0;
}
