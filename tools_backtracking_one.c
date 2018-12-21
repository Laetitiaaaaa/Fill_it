/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_backtracking_one.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:09:00 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 16:39:55 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map(int size_map)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (size_map + 2))))
		return (NULL);
	while (i <= size_map)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size_map + 2))))
			return (NULL);
		i++;
	}
	i = -1;
	while (++i <= size_map)
	{
		j = -1;
		while (++j <= size_map)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	map[i] = 0;
	return (map);
}

void	ft_display(char **map)
{
	int		i;

	i = 0;
	while (map[i] != 0)
	{
		ft_putendl(map[i]);
		i++;
	}
}

void	ft_original(t_piece **list_piece)
{
	int			i;
	t_piece		*keep;

	keep = *list_piece;
	while (keep != NULL)
	{
		i = 0;
		while (i < 4)
		{
			keep->original[i] = keep->point[i];
			i++;
		}
		keep = keep->next;
	}
}

void	ft_reset_point(t_piece **list_piece)
{
	int			i;
	t_piece		*keep;

	keep = *list_piece;
	while (keep != NULL)
	{
		i = 0;
		while (i < 4)
		{
			keep->point[i] = keep->original[i];
			i++;
		}
		keep = keep->next;
	}
}
