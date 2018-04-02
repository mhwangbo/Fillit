NAME = fillit

SRC = *.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	lib/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) $(INC) -c $(SRC_POS)

$(LIBFT):
	make -C ./lib/libft/

clean:
	rm -f $(OBJ)
	make clean -C ./lib/libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/libft/

re: fclean all

.PHONY : all, re, clean, flcean
