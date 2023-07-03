/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** parser.c
*/

#include <stdio.h> /* getline */
#include <stdlib.h> /* free */

#include "sbml_parser.h"

static tag_t *parse_tags(FILE *file)
{
    tag_t *head = NULL;
    char *buffer = NULL;
    size_t size = 0;
    tag_t *parent = NULL;
    while (getline(&buffer, &size, file) != EOF) {
        tag_t *new_head = parse_tag(buffer, &parent);
        if (new_head == NULL) {
            fclose(file);
            return NULL;
        }
        new_head->next = head;
        head = new_head;
    }
    free(buffer);
    return head;
}

tag_t *parse_file(char const *filepath)
{
    FILE *file;

    if ((file = fopen(filepath, "r")) == NULL)
        return NULL;
    tag_t *return_value = parse_tags(file);
    fclose(file);
    return return_value;
}
