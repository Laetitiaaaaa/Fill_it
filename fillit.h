/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:14:21 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 16:47:19 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				x_max;
	int				y_max;
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

int					ft_test_line_length(int *fd, char *filename);
int					ft_test_tetriminos_content(int *fd, char *filename);
int					ft_checkind_map_content_dot_dash(int *fd, char *filename);
int					ft_check_for_valid_tetriminos(int *fd,
char *filename, t_piece **list_piece);
int					ft_test_the_map(t_piece **list_piece, char *filename);
int					ft_open_map(int *fd, char *filename);
void				ft_check_for_contact_decoupe(t_piece *lst,
int *connexions, int *i, int *k);
int					ft_check_for_contact(t_piece *lst);
void				ft_coordonate_piece_decoupe(t_compteur *count,
t_piece **new_node, char *line, t_piece **list_piece);
int					ft_coordonate_piece(int fd, t_piece **list_piece);
int					ft_test_1(int fd);
int					ft_test_2(int fd);
int					ft_test_3(int fd);
char				**ft_map(int size_map);
void				ft_display(char **map);
void				ft_original(t_piece **list_piece);
void				ft_reset_point(t_piece **list_piece);
int					ft_ymax(t_piece *piece);
int					ft_xmax(t_piece *piece);
void				ft_move_x(t_piece **piece);
void				ft_move_y(t_piece **piece);
int					ft_backtracking(int *size_map, char **map,
t_piece **list_piece);
void				ft_translate_piece_decoupe(t_piece **list_piece,
int *xmin, int *ymin);
t_piece				*ft_translate_piece_origin(t_piece **list_piece);
t_piece				*ft_lst_new_piece(t_piece *new_node);
void				ft_lst_add(t_piece **lst, t_piece *new_node);
int					ft_pose_possible(t_piece *piece, char **map);
void				ft_put_piece(t_piece *piece, char **map);
void				ft_remove_piece(t_piece *piece, char **map);
int					ft_place(t_piece *piece, char **map, int size_map);

#endif
