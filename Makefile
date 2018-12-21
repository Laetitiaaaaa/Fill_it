

all:
	gcc -Wall -Wextra -Werror ft_fillit_util.c ft_lst_new_piece.c get_next_line.c main.c test_tetriminos.c backtracking.c libft/libft.a -o fillit
