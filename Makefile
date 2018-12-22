# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 15:36:23 by jchardin          #+#    #+#              #
#    Updated: 2018/12/22 11:38:55 by jchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = backtracking.c \
	  fitting.c \
	  get_next_line.c \
	  main.c \
	  test_one.c \
	  test_two.c \
	  test_three.c \
	  tools_backtracking_one.c \
	  tools_backtracking_two.c \

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

CC = gcc -c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SRC)
	make -C ./libft
	gcc -g  *.o libft/libft.a -o $(NAME)

clean:
	/bin/rm -rf *.o
	make fclean -C ./libft

fclean: clean
	/bin/rm -rf $(NAME)


re: fclean $(NAME)

me: $(NAME)
	./fillit test_map/sample.fillit



.PHONY: all clean fclean re

