/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** lookup_info.c
*/

#include <string.h>
#include <stddef.h>

#include "sbml_parser.h"

static int match_attribute(attribute_t const *attr, char const *name,
    char const *value)
{
    for (; attr != NULL; attr = attr->next) {
        if (strcmp(attr->name, name) == 0 && strcmp(attr->value, value) == 0)
            return 1;
    }
    return 0;
}

const tag_t *lookup(tag_t const *tag, char const *name, char const *value)
{
    for (; tag != NULL; tag = tag->next) {
        if (tag->name == NULL)
            continue;
        if (match_attribute(tag->attribute, name, value) == 1)
            return tag;
    }
    return NULL;
}

const tag_t *lookup_parent(tag_t const *tag, char const *name,
    tag_t const *parent)
{
    for (; tag != NULL; tag = tag->next) {
        if (tag->parent == parent && tag->name != NULL
            && strcmp(tag->name, name) == 0)
            return tag;
    }
    return NULL;
}

char const *get_attribute(attribute_t const *attribute, char const *name)
{
    for (; attribute != NULL; attribute = attribute->next) {
        if (strcmp(attribute->name, name) == 0)
            return attribute->value;
    }
    return NULL;
}
