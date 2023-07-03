/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** dash_e.c
*/

#include <string.h> /* strcmp */
#include <stdlib.h> /* malloc */
#include <stdio.h> /* printf */

#include "sbml_parser.h"

static char const *get_stoichio(tag_t const *list, tag_t const *parent,
    char const *name)
{
    tag_t const *spec_ref = lookup(list, "species", name);

    while (spec_ref != NULL) {
        if (strcmp(spec_ref->name, "speciesReference") == 0 &&
            spec_ref->parent == parent)
            return get_attribute(spec_ref->attribute, "stoichiometry");
        spec_ref = lookup(spec_ref->next, "species", name);
    }
    return NULL;
}

static void print_compound(tag_t const *tag, tag_t const *reaction,
    char const *name, char const *prefix)
{
    char const *stoichio = get_stoichio(tag, reaction, name);
    printf("%s%s %s", prefix, stoichio, name);
}

static int reactant_eq(tag_t const *tag, tag_t const *reaction)
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
        spec_ref = lookup_parent(spec_ref->next, "speciesReference", reactants);
    }
    bubble_sort(reactant_names, index);
    print_compound(tag, reactants, reactant_names[0], "");
    for (int i = 1; i < index; i++)
        print_compound(tag, reactants, reactant_names[i], " + ");
    free(reactant_names);
    return 0;
}

static int product_eq(tag_t const *tag, tag_t const *reaction)
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
    print_compound(tag, products, product_names[0], "");
    for (int i = 1; i < index; i++)
        print_compound(tag, products, product_names[i], " + ");
    free(product_names);
    return 0;
}

int reaction_equation(tag_t const *tag, tag_t const *reaction)
{
    char const *reversible = get_attribute(reaction->attribute, "reversible");

    reactant_eq(tag, reaction);
    if (strcmp(reversible, "true") == 0)
        printf(" <-> ");
    else
        printf(" -> ");
    product_eq(tag, reaction);
    printf("\n");
    return 0;
}
