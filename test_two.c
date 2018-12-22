/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:10:27 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/22 15:26:26 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_coordonate_piece_decoupe(t_compteur *count,
		t_piece **new_node, char *line, t_piece **list_piece)
{
	count->i = count->i + 1;
	if (count->i == 0)
		if (!(*new_node = ft_lst_new_piece(*new_node)))
			return (0);
	if (ft_strlen(line) > 0)
	{
		count->j = 0;
		while (line[count->j] != '\0')
		{
			if (line[count->j++] == '#')
			{
				(*new_node)->point[count->k].x = count->j;
				(*new_node)->point[count->k].y = count->i;
				count->k++;
			}
		}
	}
	if (count->i == 3)
	{
		count->k = 0;
		ft_lst_add(list_piece, *new_node);
	}
	if (count->i == 4)
		count->i = -1;
	return (1);
}

int				ft_coordonate_piece(int fd, t_piece **list_piece)
{
	char			*line;
	t_compteur		*count;
	t_piece			*new_node;

	if (!(count = malloc(sizeof(t_compteur))))
		return (0);
	count->i = -1;
	count->k = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((ft_coordonate_piece_decoupe(count, &new_node,
						line, list_piece)) == 0)
			return (0);
		free(line);
	}
	free(count);
	return (1);
}

int				ft_test_1(int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (get_next_line(fd, &line))
	{
		if (++i < 4)
			if ((int)ft_strlen(line) != 4)
				return (0);
		if (i == 4)
		{
			if ((int)ft_strlen(line) != 0)
				return (0);
			i = -1;
		}
		free(line);
	}
	if (i != 3)
		return (0);
	return (1);
}

int				ft_test_2(int fd, char *line)
{
	t_compteur		count;

	count.j = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) != 0)
		{
			count.i = -1;
			while (line[++(count.i)] != '\0')
			{
				if (line[count.i] == '#')
					count.j++;
			}
		}
		else
		{
			if (count.j != 4)
				return (0);
			count.j = 0;
		}
		free(line);
	}
	if (count.j != 4)
		return (0);
	return (1);
}

int				ft_test_3(int fd)
{
	char	*line;
	int		i;

	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] != '#' && line[i] != '.')
				return (0);
			i++;
		}
		free(line);
	}
	return (1);
}
