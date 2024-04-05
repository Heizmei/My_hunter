##
## EPITECH PROJECT, 2024
## PSU
## File description:
## Makefile
##


SRC			=	source/animation.c	\
				source/background.c	\
				source/event_manager.c	\
				source/my_pustr.c	\
				source/sprite.c	\

MAIN_SRC	=	source/main.c						\

TEST		=	\

DIR_TESTS	=	$(addprefix tests/, $(TEST))

OBJ_DIR_SRC	=	$(SRC:.c=.o)

OBJ_MAIN	=	$(MAIN_SRC:.c=.o)

OBJ			=	$(OBJ_DIR_SRC) $(OBJ_MAIN)


CPPFLAGS	=	-I include/	\


CFLAGS		=	-Wall -Wextra -ggdb3

GRAPHICS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME		=	my_hunter


$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(GRAPHICS)

all: $(NAME)


clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf unit_tests
		rm -rf *.gcov
		rm -f $(NAME)

re:		fclean all

unit_tests:	re
		mkdir unit_tests
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS)\
		$(CPPFLAGS) $(LDLIBS) --coverage -lcriterion

tests_run:	unit_tests
		./unit_tests/unit_tests

.PHONY: all clean fclean re tests_run
