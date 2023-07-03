/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** free_tag.c
*/

#include <stdlib.h> /* free */

#include "sbml_parser.h"

static void free_attribute(attribute_t *attribute)
{
    attribute_t *tmp = NULL;

    while (attribute != NULL) {
        free(attribute->name);
        free(attribute->value);
        tmp = attribute;
        attribute = attribute->next;
        free(tmp);
    }
}

void free_tag(tag_t *tag)
{
    tag_t *tmp = NULL;

    while (tag != NULL) {
        free(tag->name);
        free_attribute(tag->attribute);
        tmp = tag;
        tag = tag->next;
        free(tmp);
    }
}
