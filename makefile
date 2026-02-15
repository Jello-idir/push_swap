CC = cc
NAME = push_swap
BONUS = checker

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c data.c algo.c algo_few.c instructions.c moves.c helper.c stack_helper.c cleaning.c
SRC_BONUS = checker_bonus.c data_bonus.c moves_bonus.c stack_helper_bonus.c helper_bonus.c cleaning_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)

%_bonus.o: %_bonus.c checker.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
