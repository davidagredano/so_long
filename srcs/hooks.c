/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:48:54 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 20:58:16 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_coord	get_target_coord(t_data *data, keys_t key)
{
	t_coord	target;

	target = data->game->player;
	if (key == MLX_KEY_W)
		target.y -= 1;
	else if (key == MLX_KEY_A)
		target.x -= 1;
	else if (key == MLX_KEY_S)
		target.y += 1;
	else if (key == MLX_KEY_D)
		target.x += 1;
	return (target);
}

static void	move_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	t_coord	target;
	char	target_tile;

	data = (t_data *)param;
	target_tile = '\0';
	if (keydata.action == MLX_PRESS)
	{
		target = get_target_coord(data, keydata.key);
		target_tile = data->game->tilemap.map[target.y][target.x];
	}
	if (target_tile != '\0' && target_tile != '1')
	{
		if (target_tile == 'C')
			collectible_collect(data, target);
		player_move(data, target);
	}
}

void	hooks_setup(t_data *data)
{
	mlx_key_hook(data->graphics->mlx, move_keyhook, data);
}
