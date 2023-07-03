/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** requirement.c
*/

#include <stddef.h> /* NULL */
#include <stdlib.h> /* malloc */
#include <stdio.h>

static int is_separator(char c)
{
    if ('0' <= c && c <= '9')
        return 0;
    if ('a' <= c && c <= 'z')
        return 0;
    if ('A' <= c && c <= 'Z')
        return 0;
    return 1;
}

static int my_strlen_word(char const *str, int i)
{
    int count = 0;

    for (int j = i; !is_separator(str[j]) && str[j] != '\0'; j++) {
        count++;
    }
    return count;
}

static int nb_word_str(char const *str)
{
    int nb_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_separator(str[i]))
            nb_word++;
    }
    return nb_word;
}

static int skip_separator(char const *str, int i)
{
    for (; is_separator(str[i]) && str[i] != '\0'; i++);
    return i;
}

char **my_str_to_word_array_synthesis(char const *str)
{
    int nb_word = nb_word_str(str);
    char **array = malloc(sizeof(char *) * (nb_word + 2));
    int i = skip_separator(str, 0);
    int y = 0;
    int x = 0;
    array[0] = malloc(sizeof(char) * (my_strlen_word(str, i) + 1));
    for ( ; str[i] != '\0'; i++) {
        if (is_separator(str[i])) {
            array[y++][x] = '\0';
            i = skip_separator(str, i) - 1;
            array[y] = malloc(sizeof(char) * (my_strlen_word(str, i + 1) + 1));
            x = 0;
        } else
            array[y][x++] = str[i];
    }
    if (x != 0)
        array[y++][x] = '\0';
    array[y] = NULL;
    return array;
}
