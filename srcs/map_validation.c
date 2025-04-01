/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:01:35 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/01 13:24:54 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Checks that the exit and all collectibles are accessible.
 */
//map_check_valid_path(data) {}

/**
 * Check that is rectangular.
 * Check that is wall surrounded.
 */
static void	map_check_shape(t_data *data)
{
	char	*row_top;
	char	*row_bottom;
	int		y;

	y = 0;
	while (y < data->game.map_height)
	{
		if ((int)ft_strlen(data->game.map[y]) != data->game.map_width)
			cleanup_exit(data, "Map must be rectangular");
		if (data->game.map[y][0] != '1')
			cleanup_exit(data, "Map must be surrounded by walls");
		if (data->game.map[y][data->game.map_width - 1] != '1')
			cleanup_exit(data, "Map must be surrounded by walls");
		y++;
	}
	row_top = data->game.map[0];
	row_bottom = data->game.map[data->game.map_height - 1];
	if (ft_strspn(row_top, "1") != ft_strlen(row_top))
		cleanup_exit(data, "Map must be surrounded by walls");
	if (ft_strspn(row_bottom, "1") != ft_strlen(row_bottom))
		cleanup_exit(data, "Map must be surrounded by walls");
}

/**
 * Checks there are valid characters only.
 * Checks minimum character appearance.
 */
static void	map_check_characters(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->game.map_height)
	{
		x = 0;
		while (data->game.map[y][x] != '\0')
		{
			if (!ft_strchr("01CEP", data->game.map[y][x]))
				cleanup_exit(data, "Invalid character found in map file");
			x++;
		}
		y++;
	}
	if (map_entity_count(data, 'E') != 1)
		cleanup_exit(data, "Invalid number of 'E' in map file");
	if (map_entity_count(data, 'P') != 1)
		cleanup_exit(data, "Invalid number of 'P' in map file");
	if (map_entity_count(data, 'C') < 1)
		cleanup_exit(data, "Invalid number of 'C' in map file");
}

void	map_validate(t_data *data)
{
	map_check_characters(data);
	map_check_shape(data);
	//map_check_valid_path(data);
}
