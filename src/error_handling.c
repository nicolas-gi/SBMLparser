/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** help.c
*/

#include <string.h> /* strcmp */
#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */

#include "sbml_parser.h"

int error_handling(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("USAGE\n"
        "    ./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n"
        "DESCRIPTION\n"
        "    SBMLfile    SBML file\n"
        "    -i ID       id of the compartment, reaction or product"
        " to be extracted\n"
        "    -e          print the equation if a reaction ID is given"
        " as argument\n"
        "    -json       transform the file into a JSON file\n");
        exit(0);
    }
    return 0;
}
