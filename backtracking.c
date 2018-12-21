/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:07:20 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 16:45:11 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_pose_possible(t_piece *piece, char **map)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (map[piece->point[i].y][piece->point[i].x] != '.')
			return (-1);
		i++;
	}
	return (1);
}

void			ft_put_piece(t_piece *piece, char **map)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[piece->point[i].y][piece->point[i].x] = 'A' + piece->n;
		i++;
	}
}

void			ft_remove_piece(t_piece *piece, char **map)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[piece->point[i].y][piece->point[i].x] = '.';
		i++;
	}
}

int				ft_place(t_piece *piece, char **map, int size_map)
{
	t_point		count;

	if (piece == NULL)
		return (0);
	count.y_max = ft_ymax(piece);
	while (count.y_max <= size_map)
	{
		count.x_max = ft_xmax(piece);
		while (count.x_max <= size_map)
		{
			if (ft_pose_possible(piece, map) == 1)
			{
				ft_put_piece(piece, map);
				if (ft_place(piece->next, map, size_map) == 0)
					return (0);
				ft_remove_piece(piece, map);
			}
			ft_move_x(&piece);
			count.x_max = ft_xmax(piece);
		}
		ft_move_y(&piece);
		count.y_max = ft_ymax(piece);
	}
	ft_reset_point(&piece);
	return (-1);
}
