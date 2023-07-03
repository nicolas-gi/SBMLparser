/*
** EPITECH PROJECT, 2023
** synthese
** File description:
** skip_spaces.c
*/

static int is_space(char c)
{
    return c == ' ' || c == '\t';
}

char const *skip_spaces(char const *line)
{
    while (is_space(*line)) {
        line++;
    }
    return line;
}
