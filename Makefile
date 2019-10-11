NAME = fillit

FLAG = -Wall -Werror -Wextra

LIB = ./libft/libft.a

SRC = read_file.c valid_card.c 

OBJ=$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft

%.o : %.c
	gcc $(FLAG) $(OBJ) 