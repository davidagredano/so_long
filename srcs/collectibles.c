/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:09 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 20:48:07 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectibles_init(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->collectibles += 1;
			x++;
		}
		y++;
	}
}

void	collectible_collect(t_data *data, t_coord target)
{
	mlx_instance_t	*instance;
	size_t			i;

	data->game.collectibles -= 1;
	i = 0;
	target.x *= TILE_SIZE;
	target.y *= TILE_SIZE;
	while (i < data->graphics->images->collectible->count)
	{
		instance = &data->graphics->images->collectible->instances[i];
		if (instance->x == target.x && instance->y == target.y)
		{
			instance->enabled = false;
			break ;
		}
		i++;
	}
}
