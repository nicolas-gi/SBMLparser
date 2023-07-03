/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** main.c
*/

#include <stdlib.h> /* free */
#include <string.h> /* strcmp */
#include <stdio.h> /* printf */

#include "sbml_parser.h"

static int switch_arguments(int argc, char **argv, tag_t *tag)
{
    int return_value = 0;

    switch (argc) {
        case 2:
            sort_tag(tag);
            break;
        case 3:
            return_value = dash_i(tag, argv);
            break;
        case 4:
            return_value = dash_i(tag, argv);
            break;
        case 5:
            return_value = dash_i(tag, argv);
            break;
        default:
            return_value = 84;
    }
    free_tag(tag);
    return return_value;
}

int main(int argc, char **argv)
{
    error_handling(argc, argv);
    tag_t *tag = parse_file(argv[1]);
    if (tag == NULL)
        return 84;

    return switch_arguments(argc, argv, tag);
}
