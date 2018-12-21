/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:19:22 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 13:33:01 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_tetriminos.h"

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
	i = 0;
	while (i <= size_map)
	{
		j = 0;
		while (j <= size_map)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
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
	int	i;
	t_piece	*keep;
	
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
	int i;
	t_piece	*keep;

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

int		main(int argc, char **argv)
{
	int			size_map;
	t_piece		*list_piece;
	char		**map;

	size_map = 1;
	list_piece = NULL;
	if (argc != 2)
	{
		ft_putstr("voici mon usage = il te faut 1 seul fichier l'ami\n");
		return (0);
	}
	if (!(ft_test_the_map(&list_piece, argv[1])))
	{
		ft_putstr("error\n");
		return (1);
	}
//	ft_display_pieces(list_piece);
	list_piece = ft_translate_piece_origin(&list_piece);
	printf("translate done\n");
//	ft_display_pieces(list_piece);
	printf("on place les pieces\n");
	if (!(map = ft_map(size_map)))
		return (0);
	//	ft_display(map);

	// faire une copie malloquer de piece original;
	

printf("VIDAGE\n\n\n\n");


	ft_original(&list_piece);
	while (ft_place(list_piece, map, size_map) == -1)
	{
		size_map++;
		free(map);
		map = ft_map(size_map);
		ft_reset_point(&list_piece);
	}
	ft_display(map);
	free(map);
	return (0);
}
