/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** list_to_array.c
*/


#include <stdlib.h> /* NULL &  malloc */
#include <string.h> /* strncmp */

#include "sbml_parser.h"

int count_list(tag_t const *tag)
{
    int count = 0;

    while (tag != NULL) {
        if (tag->name != NULL && strncmp(tag->name, "listOf", 6) != 0)
            count++;
        tag = tag->next;
    }
    return count;
}

char const **list_to_array(tag_t const *tag)
{
    int index = 0;
    int count = count_list(tag);
    char const **list_tag = malloc(sizeof(char *) * (count + 1));

    for (; index != count; index++) {
        while (tag->name == NULL || strncmp(tag->name, "listOf", 6) == 0) {
            tag = tag->next;
        }
        list_tag[index] = tag->name;
        tag = tag->next;
    }
    list_tag[count] = NULL;

    return list_tag;
}
