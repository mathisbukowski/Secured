##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## Makefile
##
SRC = src/utils/hash_func.c\
		src/utils/my_strlen.c\
		src/utils/my_put_nbr.c\
		src/utils/my_putchar.c\
		src/utils/my_putstr.c\
		src/utils/my_strcmp.c\
		src/utils/my_strdup.c\
		src/utils/mini_printf.c\
		src/hashtable/add_hashtable.c\
		src/hashtable/delete_hashtable.c\
		src/commands/ht_dump.c\
		src/commands/ht_search.c\
		src/commands/ht_insert.c\
		src/commands/ht_delete.c\
		src/utils/my_strcpy.c\

SRC_UNIT = src/load_map.c\

OBJ = $(SRC:.c=.o)

NAME = libhashtable.a

CFLAGS = -g

CRI = --coverage -lcriterion

TEST_FILE = unit_tests

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		make clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run: clean
		gcc -o $(TEST_FILE) $(SRC) tests/test_hashtable.c $(CRI)
		./$(TEST_FILE) --verbose --full-stats

gcovr_branches:
		gcovr --exclude tests/ --branches
