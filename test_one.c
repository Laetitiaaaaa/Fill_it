/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:59:46 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/22 16:21:11 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_test_line_length(int *fd, char *filename)
{
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!ft_test_1(*fd))
		return (0);
	if (close(*fd) == -1)
		return (0);
	return (1);
}

int				ft_test_tetriminos_content(int *fd, char *filename)
{
	char	*line;

	line = NULL;
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!(ft_test_2(*fd, line)))
		return (0);
	if (close(*fd) == -1)
		return (0);
	return (1);
}

int				ft_checkind_map_content_dot_dash(int *fd, char *filename)
{
	if (!(ft_open_map(fd, filename)))
		return (0);
	if (!(ft_test_3(*fd)))
		return (0);
	if (close(*fd) == -1)
		return (0);
	return (1);
}

int				ft_check_for_valid_tetriminos(int *fd,
		char *filename, t_piece **list_piece)
{
	if (!(ft_open_map(fd, filename)))
		return (0);
	if ((ft_coordonate_piece(*fd, list_piece)) == 0)
		return (0);
	if (!(ft_check_for_contact(*list_piece)))
	{
		ft_free_lst(list_piece);
		return (0);
	}
	if (close(*fd) == -1)
		return (0);
	return (1);
}

int				ft_test_the_map(t_piece **list_piece, char *filename)
{
	int		fd;

	*list_piece = NULL;
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
