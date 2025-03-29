/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:48:54 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 15:35:29 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	char	target_tile;

	data = (t_data *)param;
	target_tile = '\0';
	if (keydata.action == MLX_PRESS)
		target_tile = tilemap_get_target_tile(data->game, keydata.key);
	if (target_tile != '\0' && target_tile != '1')
	{
		player_move(data->game, data->graphics->images, keydata.key);
	}
}

void	hooks_setup(t_data *data)
{
	mlx_key_hook(data->graphics->mlx, move_keyhook, data);
}
