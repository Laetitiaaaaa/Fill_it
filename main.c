/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:19:22 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 18:23:03 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			size_map;
	t_piece		*list_piece;
	char		**map;

	size_map = 1;
	list_piece = NULL;
	map = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	if (!(ft_test_the_map(&list_piece, argv[1])))
	{
		ft_putstr("error\n");
		return (1);
	}
	list_piece = ft_translate_piece_origin(&list_piece);
	if ((ft_backtracking(&size_map, map, &list_piece) == 0))
		return (0);
	return (0);
}

int		ft_backtracking(int *size_map, char **map, t_piece **list_piece)
{
	if (!(map = ft_map(*size_map)))
		return (0);
	ft_original(list_piece);
	while (ft_place(*list_piece, map, *size_map) == -1)
	{
		*size_map = *size_map + 1;
		free(map);
		if (!(map = ft_map(*size_map)))
			return (0);
		ft_reset_point(list_piece);
	}
	ft_display(map);
	free(map);
	return (1);
}
