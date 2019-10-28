# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvassago <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 16:50:41 by cvassago          #+#    #+#              #
#    Updated: 2019/10/28 14:50:23 by mnidokin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

COMP = gcc

FLAG = -Wall -Werror -Wextra

LIBINCLUDES = -I ./libft

SRC = 	reader.c\
		coord.c\
		map.c\
		map_oper.c\
		solver.c\
		main.c\
		errors.c\
		coord_move.c\

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./libft -I ./includes

LIB = ./libft/libft.a

all: $(NAME)

$(NAME) : $(LIB) $(OBJ)
	@ $(COMP) $(FLAG) -L./libft -lft -o $(NAME) $(OBJ) $(LIB)

%.o : ./src/%.c
	@ $(COMP) $(FLAG) $(LIBINCLUDES) -I ./includes/ -o $@ -c $<

$(LIB) :
	@ make -C ./libft/

clean:
	@ rm -rf $(OBJ)
	@ make clean -C ./libft/

fclean: clean
	@ rm -rf $(NAME)
	@ make fclean -C ./libft/

re: fclean all
