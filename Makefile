##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC		=		my_hunter.c	\
				my_putstr.c	\
				event_while.c	\
				disp_sprite.c	\
				main_loop.c		\
				set_texture.c	\
				free_funct.c	\
				click_event.c	\
				while_clock.c	\
				game_over_screen.c	\
				menu.c	\

DIR_SRC        =    $(addprefix source/, $(SRC))

MAIN_SRC    =    source/main.c                        \

TEST        =    unit_test.c\

DIR_TESTS    =    $(addprefix tests/, $(TEST))

OBJ_DIR_SRC    =    $(DIR_SRC:.c=.o)

OBJ_MAIN    =    $(MAIN_SRC:.c=.o)

OBJ            =    $(OBJ_DIR_SRC) $(OBJ_MAIN)

CPPFLAGS    =    -I include/	\

CFLAGS        =    -Wall -Wextra -ggdb3

GRAPHICS	= -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME        =    my_hunter

$(NAME):    $(OBJ)
		gcc -o $(NAME) -g $(CFLAGS) $(OBJ) $(GRAPHICS)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf unit_tests
		rm -rf *.gcov
		rm -f $(NAME)

re:        fclean all

unit_tests:    re
		mkdir unit_tests
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS)\
		$(CPPFLAGS) $(LDLIBS) --coverage -lcriterion

tests_run:    unit_tests
		./unit_tests/unit_tests

.PHONY: all clean fclean re tests_run
