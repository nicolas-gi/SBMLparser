/*
** EPITECH PROJECT, 2023
** SBMLparser
** File description:
** attributes_to_array.c
*/

#include <stdlib.h> /* malloc */

#include "sbml_parser.h"

static int count_attributes(attribute_t const *attribute)
{
    int count = 0;

    while (attribute != NULL) {
        if (attribute->name != NULL)
            count++;
        attribute = attribute->next;
    }
    return count;
}

char const **attributes_to_array(attribute_t const *attribute)
{
    int index = 0;
    int count = count_attributes(attribute);
    char const **list_attribute = malloc(sizeof(char *) * (count + 1));

    for (; index != count; index++) {
        while (attribute->name == NULL) {
            attribute = attribute->next;
        }
        list_attribute[index] = attribute->name;
        attribute = attribute->next;
    }
    list_attribute[count] = NULL;

    return list_attribute;
}
