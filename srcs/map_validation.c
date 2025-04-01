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

static void	explore(t_data *copy, int x, int y)
{
	if (copy->game.map[y][x] == '1' || copy->game.map[y][x] == 'X')
		return ;
	if (copy->game.map[y][x] == 'C')
		copy->game.collectibles++;
	if (copy->game.map[y][x] == 'E')
	{
		copy->game.exit.x = x;
		copy->game.exit.x = y;
	}
	copy->game.map[y][x] = 'X';
	explore(copy, x, y - 1);
	explore(copy, x + 1, y);
	explore(copy, x, y + 1);
	explore(copy, x - 1, y);
}

/**
 * Checks that the exit and all collectibles are accessible from the player's
 * starting position.
 */
void	map_check_valid_path(t_data *data, char *filename)
{
	t_data	copy;

	ft_bzero(&copy, sizeof(t_data));
	copy.game.map_height = data->game.map_height;
	copy.game.map = map_create(data, filename);
	if (!copy.game.map)
		cleanup_exit(data, "Failed to allocate memory for map_copy");
	copy.game.player = map_entity_find(data, 'P');
	explore(&copy, copy.game.player.x, copy.game.player.y);
	if (copy.game.exit.x == 0 && copy.game.exit.y == 0)
	{
		map_destroy(&copy);
		cleanup_exit(data, "Invalid map: Exit is not accessible");
	}
	else if (copy.game.collectibles != map_entity_count(data, 'C'))
	{
		map_destroy(&copy);
		cleanup_exit(data, "Invalid map: Some collectibles are not accessible");
	}
	map_destroy(&copy);
}

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

void	map_validate(t_data *data, char *filename)
{
	map_check_characters(data);
	map_check_shape(data);
	map_check_valid_path(data, filename);
}
