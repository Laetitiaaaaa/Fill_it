# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 15:36:23 by jchardin          #+#    #+#              #
#    Updated: 2018/12/21 17:38:26 by jchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = backtracking.c \
	  fitting.c \
	  get_next_line.c \
	  main.c \
	  test_one.c \
	  test_two.c \
	  test_three.c \
	  tools_backtracking_one.c \
	  tools_backtracking_two.c \
	  libft/libft.a


CFLAG = -Wall -Wextra -Werror
CC = gcc
NAME = fillit

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(SRC) -o $(NAME)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean $(NAME)

me: $(NAME)
	./fillit test_map/sample.fillit



.PHONY: all clean fclean re

