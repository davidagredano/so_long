/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:16:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/02 15:11:26 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_count_rows(t_data *data, char *filename)
{
	int		fd;
	char	*row;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		cleanup_exit(data, "Failed to open map file");
	count = 0;
	while (count >= 0)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		free(row);
		count++;
	}
	if (close(fd) == -1)
		cleanup_exit(data, "Failed to close map file");
	if (count == 0)
		cleanup_exit(data, "Map file is empty");
	else if (count < 0)
		cleanup_exit(data, "Map file is too large");
	return (count);
}

int	map_count_columns(t_data *data)
{
	int	count;

	count = 0;
	while (data->game.map[0][count] != '\0')
	{
		count++;
		if (count < 0)
			cleanup_exit(data, "Too long rows in map file");
	}
	return (count);
}

void	map_destroy(t_data *data)
{
	int	row;

	row = 0;
	while (row < data->game.map_height)
	{
		if (data->game.map[row])
			free(data->game.map[row]);
		row++;
	}
	free(data->game.map);
	data->game.map = NULL;
}

t_coord	map_entity_find(t_data *data, char type)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < data->game.map_height)
	{
		coord.x = 0;
		while (coord.x < data->game.map_width)
		{
			if (data->game.map[coord.y][coord.x] == type)
				return (coord);
			coord.x++;
		}
		coord.y++;
	}
	coord.x = -1;
	coord.y = -1;
	return (coord);
}

t_uint	map_entity_count(t_data *data, char type)
{
	t_uint	count;
	t_coord	coord;

	count = 0;
	coord.y = 0;
	while (coord.y < data->game.map_height)
	{
		coord.x = 0;
		while (coord.x < data->game.map_width)
		{
			if (data->game.map[coord.y][coord.x] == type)
				count++;
			coord.x++;
		}
		coord.y++;
	}
	return (count);
}
