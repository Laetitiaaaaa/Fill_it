/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:59:46 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/21 16:44:34 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_test_line_length(int *fd, char *filename)
{
	ft_putstr("test1 CHECKING LINES LENGTH = 4 then 0->");
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!ft_test_1(*fd))
	{
		ft_putstr("Error in line length\n");
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	return (1);
}

int				ft_test_tetriminos_content(int *fd, char *filename)
{
	ft_putstr("test2 CHECKING TETRIMINOS CONTENT ONLY 4 # -> ");
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!(ft_test_2(*fd)))
	{
		ft_putstr("Error in Tetriminos\n");
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	return (1);
}

int				ft_checkind_map_content_dot_dash(int *fd, char *filename)
{
	ft_putstr("test3 CHECKING MAP CONTENT ONLY # AND . ->");
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!(ft_test_3(*fd)))
	{
		ft_putstr("Error map must content only # and .\n");
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	return (1);
}

int				ft_check_for_valid_tetriminos(int *fd,
		char *filename, t_piece **list_piece)
{
	ft_putstr("test4 CHECKING IF EACH BLOCK IS IN CONTACT WITH AN OTHER ->");
	if (!(ft_open_map(fd, filename)))
		return (0);
	ft_coordonate_piece(*fd, list_piece);
	if (!(ft_check_for_contact(*list_piece)))
	{
		ft_putstr("Error in a block not connected to an other\n");
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	ft_putstr(" OK\n");
	return (1);
}

int				ft_test_the_map(t_piece **list_piece, char *filename)
{
	int		fd;

	*list_piece = NULL;
	ft_putstr("CHECKING THE MAP\n\n");
	if (!(ft_test_line_length(&fd, filename)))
		return (0);
	if (!(ft_test_tetriminos_content(&fd, filename)))
		return (0);
	if (!(ft_checkind_map_content_dot_dash(&fd, filename)))
		return (0);
	if (!(ft_check_for_valid_tetriminos(&fd, filename, list_piece)))
		return (0);
	return (1);
}
