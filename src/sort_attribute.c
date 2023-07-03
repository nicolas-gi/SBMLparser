/*
** EPITECH PROJECT, 2023
** SBMLparser
** File description:
** sort_attribute.c
*/

#include <stdio.h> /* printf */
#include <string.h> /* strcmp */
#include <stdlib.h> /* free */

#include "sbml_parser.h"

//the continue in for loop is for lisibility
static int count_array(char const **array)
{
    int count = 0;

    for (; array[count] != NULL; count++) {
        continue;
    }
    return count;
}

static void sort_attribute(attribute_t const *attribute)
{
    char const **list_of_names = attributes_to_array(attribute);
    char const **uniques = unique_names(list_of_names);
    int count_uniques = count_array(uniques);

    bubble_sort(uniques, count_uniques);

    for (int index = 0; index != count_uniques; index++)
        printf("--->%s\n", uniques[index]);
    free(list_of_names);
    free(uniques);
}

static void find_and_print_attributes(tag_t const *tag, char const *name)
{
    for (; tag != NULL; tag = tag->next) {
        if (tag->name == NULL)
            continue;
        if (strcmp(tag->name, name) == 0)
            return sort_attribute(tag->attribute);
    }
}

void sort_tag(tag_t const *tag)
{
    char const **list_of_names = list_to_array(tag);
    char const **uniques = unique_names(list_of_names);
    int count_uniques = count_array(uniques);

    bubble_sort(uniques, count_uniques);
    for (int index = 0; index != count_uniques; index++) {
        printf("%s\n", uniques[index]);
        find_and_print_attributes(tag, uniques[index]);
    }
    free(list_of_names);
    free(uniques);
}
