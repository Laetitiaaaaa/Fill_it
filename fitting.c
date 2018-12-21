/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fitting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:12:19 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 16:45:01 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_translate_piece_decoupe(t_piece **list_piece,
int *xmin, int *ymin)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		if ((*list_piece)->point[j].x < *xmin)
			*xmin = (*list_piece)->point[j].x;
		if ((*list_piece)->point[j].y < *ymin)
			*ymin = (*list_piece)->point[j].y;
		j++;
	}
	j = 0;
	while (j < 4)
	{
		(*list_piece)->point[j].x = (*list_piece)->point[j].x - *xmin;
		(*list_piece)->point[j].y = (*list_piece)->point[j].y - *ymin;
		j++;
	}
}

t_piece			*ft_translate_piece_origin(t_piece **list_piece)
{
	int			xmin;
	int			ymin;
	t_piece		*lst_origin;

	lst_origin = *list_piece;
	while (*list_piece)
	{
		ymin = (*list_piece)->point[0].y;
		xmin = (*list_piece)->point[0].x;
		ft_translate_piece_decoupe(list_piece, &xmin, &ymin);
		*list_piece = (*list_piece)->next;
	}
	return (lst_origin);
}

t_piece			*ft_lst_new_piece(t_piece *new_node)
{
	static int n = 0;

	new_node = (t_piece*)malloc(sizeof(t_piece));
	new_node->point = (t_point*)malloc(sizeof(t_point) * 4);
	new_node->original = (t_point*)malloc(sizeof(t_point) * 4);
	new_node->move.x = 0;
	new_node->move.y = 0;
	new_node->n = n;
	new_node->next = NULL;
	n++;
	return (new_node);
}

void			ft_lst_add(t_piece **lst, t_piece *new_node)
{
	t_piece	*keep;

	keep = *lst;
	if (keep != NULL && new_node != NULL)
	{
		while ((keep)->next != NULL)
		{
			(keep) = (keep)->next;
		}
		(keep)->next = new_node;
	}
	if (*lst == NULL)
	{
		*lst = new_node;
	}
}
