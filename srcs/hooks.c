/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:48:54 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 22:09:20 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_coord	get_target_coord(t_data *data, keys_t key)
{
	t_coord	target;

	target = data->game.player;
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
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		target = get_target_coord(data, keydata.key);
		target_tile = data->game.map[target.y][target.x];
		if (target_tile != '\0' && ft_strchr("0CE", target_tile))
		{
			movements_add_one(&data->game);
			movements_log(&data->game);
			if (target_tile == 'C')
				collectible_collect(data, target);
			else if (target_tile == 'E' && data->game.collectibles == 0)
				mlx_close_window(data->mlx);
			player_move(data, target);
		}
	}
}

void	hooks_setup(t_data *data)
{
	mlx_key_hook(data->mlx, move_keyhook, data);
}
