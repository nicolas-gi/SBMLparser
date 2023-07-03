/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** free_array.c
*/

#include <stdlib.h> /* free */

void free_array(char const **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free((void *)array[i]);
    free(array);
}
