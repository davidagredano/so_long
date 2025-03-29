/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:43:34 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 15:33:19 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_init(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->tilemap.map;
	y = 0;
	while (y < game->tilemap.height)
	{
		x = 0;
		while (x < game->tilemap.width)
		{
			if (map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	player_move(t_game *game, t_images *images, keys_t key)
{
	if (key == MLX_KEY_W)
	{
		game->player.y -= 1;
		images->player->instances[0].y -= 1 * TILE_SIZE;
	}
	else if (key == MLX_KEY_A)
	{
		game->player.x -= 1;
		images->player->instances[0].x -= 1 * TILE_SIZE;
	}
	else if (key == MLX_KEY_S)
	{
		game->player.y += 1;
		images->player->instances[0].y += 1 * TILE_SIZE;
	}
	else if (key == MLX_KEY_D)
	{
		game->player.x += 1;
		images->player->instances[0].x += 1 * TILE_SIZE;
	}
}
