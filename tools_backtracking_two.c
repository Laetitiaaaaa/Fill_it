/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_backtracking_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:11:21 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 16:12:04 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_ymax(t_piece *piece)
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

int				ft_xmax(t_piece *piece)
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

void			ft_move_x(t_piece **piece)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		(*piece)->point[i].x = (*piece)->point[i].x + 1;
		i++;
	}
}

void			ft_move_y(t_piece **piece)
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
