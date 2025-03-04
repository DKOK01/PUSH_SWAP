CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC		= Push_Swap.c Input_Handling.c Utils.c Swap_Operations.c \
		Push_Operations.c Rotate_Operations.c Reverse_Rotate_Operations.c \
		Sort_Small.c Sort_Large.c
OBJ		= $(SRC:.c=.o)

BONUS_SRC	=
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

NAME	= push_swap
BONUS	= checker

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME) $(BONUS)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all