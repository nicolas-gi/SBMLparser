##
## EPITECH PROJECT, 2023
## sbmlparser
## File description:
## Makefile
##

NAME = SBMLparser

CC ?= gcc

CPPFLAGS += -iquote include/

CFLAGS += -Wall -Wextra

SRC_DIR = src/

SRC = main.c                \
      error_handling.c      \
	  skip_spaces.c         \
	  parse_file.c          \
	  parse_tag.c           \
	  parse_attribute.c     \
	  list_to_array.c       \
	  attributes_to_array.c \
	  fill_unique_names.c   \
	  bubble_sort.c         \
	  sort_attribute.c      \
	  lookup_info.c         \
	  free_tag.c            \
	  dash_i.c              \
	  handle_reaction.c     \
	  dash_e.c              \
	  free_array.c

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -o $(NAME) $(OBJ)

clean :
	@$(RM) $(OBJ)
	@$(RM) $(wildcard *.o)

fclean : clean
	@$(RM) $(NAME)
	@$(RM) coding-style-reports.log
	@$(RM) $(wildcard vgcore.*)

re : fclean all

debug : re
debug : export CFLAGS += -g3

.PHONY : all clean fclean re debug
