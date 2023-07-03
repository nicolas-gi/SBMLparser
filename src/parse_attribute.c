/*
** EPITECH PROJECT, 2023
** synthese
** File description:
** parse_attribute.c
*/

#include <stdlib.h> /* malloc */
#include <string.h> /* strchr */

#include "sbml_parser.h"

attribute_t *parse_attribute(char const *line)
{
    attribute_t *attribute = malloc(sizeof(attribute_t));

    char const *start_name = line;
    char const *end_name = strchr(start_name, '=');
    int size_name = end_name - start_name;
    char const *start_value = end_name + 2;
    char const *end_value = strchr(start_value, '"');
    int size_value = end_value - start_value;

    attribute->name = strndup(start_name, size_name);
    attribute->value = strndup(start_value, size_value);

    end_value = skip_spaces(end_value + 1);
    if (*end_value == '>' || *end_value == '/') {
        attribute->next = NULL;
    } else {
        attribute->next = parse_attribute(end_value);
    }
    return attribute;
}
