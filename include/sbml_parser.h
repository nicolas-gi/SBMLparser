/*
** EPITECH PROJECT, 2023
** sbmlparser
** File description:
** sbml_parser.h
*/

#ifndef SBMLPARSER_H
    #define SBMLPARSER_H

typedef struct attribute_s {
    char *name;
    char *value;
    struct attribute_s *next;
} attribute_t;

typedef struct tag_s {
    char *name;
    attribute_t *attribute;
    struct tag_s *parent;
    struct tag_s *next;
} tag_t;

// -h & check for nb of arguments
int error_handling(int argc, char **argv);

// check a space in a line and skip it
char const *skip_spaces(char const *line);

// bubble_sort
void bubble_sort(char const **list, int size);

// list
char const **list_to_array(tag_t const *tag);
char const **attributes_to_array(attribute_t const *attribute);

// Count the number of tag in the list, then check if the tag is already
// in the list, if not, add it to the list.
char const **unique_names(char const * const *names);

int count_list(tag_t const *tag);

// Parse the file and return a list of tag.
tag_t *parse_file(char const *filepath);

// Parse a line and return a tag.
tag_t *parse_tag(char const *line, tag_t **parent);

// Parse a line and return an attribute.
attribute_t *parse_attribute(char const *line);

// Transform list of tag to array, then bring out the unique names,
// then sort the uniques alphabetically.
void sort_tag(tag_t const *tag);

// lookup
const tag_t *lookup(tag_t const *tag, char const *name, char const *value);
const tag_t *lookup_parent(tag_t const *tag, char const *name,
    tag_t const *parent);

// dash_i
int dash_i(tag_t const *tag, char **argv);

// handle_products & handle_reactants
int handle_reaction(tag_t const *tag, tag_t const *found, char const *arg,
    char const *flag);

// handle_flag_dash_e
int reaction_equation(tag_t const *tag, tag_t const *reaction);

// get_attribute
char const *get_attribute(attribute_t const *attribute, char const *name);

// free
void free_array(char const **array);
void free_tag(tag_t *tag);

#endif /* SBML_PARSER_H */
