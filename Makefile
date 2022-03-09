NAME	=	push_swap

PATH_LIBFT	=	./librarie/libft
LIBFT	=	$(PATH_LIBFT)/libft.a

I_PUSH_SWAP	=	-I ./include

I_OBJ	=	-I ./ -I ./librarie/libft/
LINKS	=	-I ./ -I ./librarie/libft/ -L ./librarie/libft/ -lft

CC	=	gcc
#CFLAGS	=	-Wall -Wextra -Werror

SRC_DIR	=		sources
SRC_FILES	=	push_swap.c \
				argv_setup.c \
				swap_move.c \
				push_move.c \
				rr_mov.c \
				rr_rev_mov.c \
				sorted_stack_checker.c \
				max_min_num.c \
				sort_min_5.c \
				free.c

SRC	=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR	=	objects
OBJ	=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FS	=	-g3

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ_DIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME) $(I_PUSH_SWAP)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(FS) -c $< -o $@ $(I_OBJ) $(I_PUSH_SWAP)

$(LIBFT):
		make -C $(PATH_LIBFT)

$(OBJ_DIR):
		mkdir objects

clean:
		rm -rf $(OBJ_DIR)
		make -C $(PATH_LIBFT) clean

fclean:	clean
		rm -rf $(NAME)
		make -C $(PATH_LIBFT) fclean

re: fclean all

valgrind:	$(NAME)
		make
		valgrind --leak-check=full --show-leak-kinds=all ./push_swap 43 5 70 81 82 88 50 55 3 59 93 75 80 17 35 16 74 25 1 100 84 65 34 60 91 79 27 4 46 86 23 96 44 87 11 9 72 10 7 32 36 2 48 6 97 77 52 22 71 89 57 42 37 33 67 49 63 13 64 19 98 8 51 24 56 66 41 47 15 61 83 39 40 94 12 92 45 85 31 58 53 54 99 78 95 20 90 38 18 69 62 68 29 14 28 21 30 76 26 73
		
.PHONY:	all clean fclean re