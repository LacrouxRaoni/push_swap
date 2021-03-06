NAME	=	push_swap

PATH_LIBFT	=	./librarie/libft
LIBFT	=	$(PATH_LIBFT)/libft.a

I_PUSH_SWAP	=	-I ./include

I_OBJ	=	-I ./ -I ./librarie/libft/
LINKS	=	-I ./ -I ./librarie/libft/ -L ./librarie/libft/ -lft

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC_DIR		=	sources
SRC_FILES	=	push_swap.c \
				argv_setup.c \
				swap_move.c \
				push_move.c \
				rr_mov.c \
				rr_rev_mov.c \
				sorted_stack_checker.c \
				max_min_num.c \
				sort_min_5.c \
				sort_max_500.c \
				sort_stack_b.c \
				long_atoi.c \
				free.c

SRC	=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR	=	objects
OBJ	=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FS	=	-g3

RANDOM	=	$(seq 1 100 | shuf | tr '\n' ' ')

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
		valgrind --leak-check=full --show-leak-kinds=all ./push_swap 4 2 a
		
.PHONY:	all clean fclean re