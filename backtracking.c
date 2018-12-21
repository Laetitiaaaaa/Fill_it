/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:22:13 by llejeune          #+#    #+#             */
/*   Updated: 2018/12/21 13:52:36 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

int		ft_ymax(t_piece *piece)
{
	int	i;
	int	ymax;

	i = 0;
	ymax = 0;
	while (i < 4)
	{
		if (piece->point[i].y > ymax)
			ymax = piece->point[i].y;
		i++;
	}
	return (ymax);
}

int		ft_xmax(t_piece *piece)
{
	int	i;
	int	xmax;

	i = 0;
	xmax = 0;
	while (i < 4)
	{
		if (piece->point[i].x > xmax)
			xmax = piece->point[i].x;
		i++;
	}
	return (xmax);
}

void		ft_move_x(t_piece **piece)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*piece)->point[i].x = (*piece)->point[i].x + 1;
		i++;
	}
}

void		ft_move_y(t_piece **piece)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*piece)->point[i].x = (*piece)->original[i].x;
		(*piece)->point[i].y = (*piece)->point[i].y + 1;
		i++;
	}
}

int		ft_pose_possible(t_piece *piece, char **map)
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

void	ft_put_piece(t_piece *piece, char **map)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[piece->point[i].y][piece->point[i].x] = 'A' + piece->n;
		i++;
	}
}

void	ft_remove_piece(t_piece *piece, char **map)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map[piece->point[i].y][piece->point[i].x] = '.';
		i++;
	}
}


int		ft_place(t_piece *piece, char **map, int size_map)
{
	int	y_max;
	int	x_max;

	if (piece == NULL)
		return (0);
	y_max = ft_ymax(piece);
	while (y_max <= size_map)
	{
		x_max = ft_xmax(piece);
		while (x_max <= size_map)
		{
			if (ft_pose_possible(piece, map) == 1)
			{
				ft_put_piece(piece, map);
				//ft_display(map);
				if (ft_place(piece->next, map, size_map) == 0)
					return (0);
				ft_remove_piece(piece, map);
			}
			ft_move_x(&piece);
			x_max = ft_xmax(piece);
		}
		ft_move_y(&piece);
		y_max = ft_ymax(piece);
	}
	ft_reset_point(&piece);
	return (-1);
}



