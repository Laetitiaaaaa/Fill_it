/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tetriminos.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:23:17 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 11:20:47 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_TETRIMINOS_H
# define TEST_TETRIMINOS_H

# include <stdio.h>
# include <fcntl.h>
# include "../Get_Next_Line/get_next_line.h"
# include "libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_piece
{
	t_point			*point;
	t_point			*original;
	t_point			move;
	int				n;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_compteur
{
	int				i;
	int				j;
	int				k;
}					t_compteur;

int					ft_test_the_map(t_piece **list_piece, char *filename);
int					ft_open_map(int *fd, char *filename);
int					ft_test_1(int fd);
int					ft_test_2(int fd);
int					ft_test_3(int fd);
int					ft_coordonate_piece(int fd, t_piece **list_piece);
t_piece				*ft_lst_new_piece(t_piece *new_node);
void				ft_lst_add(t_piece **lst, t_piece *new_node);
int					ft_display_pieces(t_piece *list_piece);
int					ft_check_for_contact(t_piece *lst);
t_piece				*ft_display_coordonee(t_piece *elem);
t_piece				*ft_translate_piece_origin(t_piece **list_piece);
int					ft_ymax(t_piece *piece);
int					ft_xmax(t_piece *piece);
void				ft_move_x(t_piece **piece);
void				ft_move_y(t_piece **piece);
int					ft_pose_possible(t_piece *piece, char **map);
void				ft_put_piece(t_piece *piece, char **map);
void				ft_remove_piece(t_piece *piece, char **map);
char				**ft_map(int size_map);
void				ft_display(char **map);
int					ft_place(t_piece *piece, char **map, int size_map);
void				ft_reset_point(t_piece **list_piece);

#endif
