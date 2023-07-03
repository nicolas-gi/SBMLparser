/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** sort.c
*/

#include <stddef.h> /* NULL */
#include <string.h> /* strcmp */

static void swap(char const **a, char const **b)
{
    char const *c = *a;
    *a = *b;
    *b = c;
}

static void sorting(char const **left, char const **right)
{
    if (strcmp(*left, *right) > 0)
        swap(left, right);
}

void bubble_sort(char const **list, int size)
{
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++) {
            sorting(&list[i], &list[i + 1]);
        }
    }
}
