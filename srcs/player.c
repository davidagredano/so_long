/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:43:34 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 20:48:48 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_data *data, t_coord target)
{
	t_coord	current;

	current = data->game.player;
	if (current.x == data->game.exit.x && current.y == data->game.exit.y)
		data->game.map[current.y][current.x] = 'E';
	else
		data->game.map[current.y][current.x] = '0';
	data->game.map[target.y][target.x] = 'P';
	data->game.player = target;
	data->graphics->images->player->instances[0].x = target.x * TILE_SIZE;
	data->graphics->images->player->instances[0].y = target.y * TILE_SIZE;
}
