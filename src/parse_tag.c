/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** parse_tag.c
*/

#include <string.h> /* strncmp */
#include <stdlib.h> /* malloc */

#include "sbml_parser.h"

static tag_t *alloc_tag(void)
{
    tag_t *tag = malloc(sizeof(tag_t));

    if (tag == NULL)
        return NULL;

    tag->name = NULL;
    tag->attribute = NULL;
    tag->parent = NULL;
    tag->next = NULL;
    return tag;
}

static tag_t *manage_parent(char const *line, tag_t *parent, tag_t *tag)
{
    tag->parent = parent;
    if (strncmp(line, "</", 2) == 0)
        return parent->parent;
    if (strstr(line, "/>") != NULL)
        return parent;
    return tag;
}

tag_t *parse_tag(char const *line, tag_t **parent)
{
    line = skip_spaces(line);
    char const *tag_space = strchr(line, ' ');
    char const *tag_end = strchr(line, '>');
    tag_t *tag = alloc_tag();
    if (tag == NULL)
        return NULL;
    *parent = manage_parent(line, *parent, tag);
    if (strncmp(line, "<listOf", 7) == 0) {
        size_t size_end = tag_end - line - 1;
        tag->name = strndup(line + 1, size_end);
        return tag;
    }
    if (strncmp(line, "<?", 2) == 0)
        return tag;
    if (strncmp(line, "</", 2) == 0)
        return tag;
    size_t size_tag = tag_space - line - 1;
    tag->name = strndup(line + 1, size_tag);
    tag->attribute = parse_attribute(tag_space + 1);
    return tag;
}
