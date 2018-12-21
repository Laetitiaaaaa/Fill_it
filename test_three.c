/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:03:25 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 16:06:51 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_open_map(int *fd, char *filename)
{
	if ((*fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("file descriptor failure");
		return (0);
	}
	return (1);
}

void			ft_check_for_contact_decoupe(t_piece *lst,
int *connexions, int *i, int *k)
{
	if (lst->point[*k].x == lst->point[*i].x)
	{
		if (lst->point[*k].y == lst->point[*i].y - 1)
			(*connexions)++;
		if (lst->point[*k].y == lst->point[*i].y + 1)
			(*connexions)++;
	}
	if (lst->point[*k].y == lst->point[*i].y)
	{
		if (lst->point[*k].x == lst->point[*i].x - 1)
			(*connexions)++;
		if (lst->point[*k].x == lst->point[*i].x + 1)
			(*connexions)++;
	}
}

int				ft_check_for_contact(t_piece *lst)
{
	int		k;
	int		i;
	int		connexions;

	while (lst != NULL)
	{
		k = 0;
		connexions = 0;
		while (k < 4)
		{
			i = 0;
			while (i < 4)
			{
				if (i != k)
					ft_check_for_contact_decoupe(lst, &connexions, &k, &i);
				i++;
			}
			k++;
		}
		if (connexions <= 4)
			return (0);
		lst = lst->next;
	}
	return (1);
}
