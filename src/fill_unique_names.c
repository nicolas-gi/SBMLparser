/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** fill_unique_names.c
*/

#include <string.h> /* strcmp */
#include <stdlib.h> /* malloc */

static int exist_in_list(char const *str, char const * const *list, int size)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}

char const **unique_names(char const * const *names)
{
    int count_names = 0;
    int count_uniques = 0;

    for (int i = 0; names[i] != NULL; i++)
        count_names++;

    char const **uniques = malloc(sizeof(char *) * (count_names + 1));

    for (int i = 0; names[i] != NULL; i++) {
        if (!exist_in_list(names[i], uniques, count_uniques)) {
            uniques[count_uniques] = names[i];
            count_uniques++;
        }
    }
    uniques[count_uniques] = NULL;

    return uniques;
}
