/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 12:48:54 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/02 15:11:00 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_move(t_data *data, t_coord target)
{
	t_coord	current;

	current = data->game.player;
	if (current.x == data->game.exit.x && current.y == data->game.exit.y)
		data->game.map[current.y][current.x] = 'E';
	else
		data->game.map[current.y][current.x] = '0';
	data->game.map[target.y][target.x] = 'P';
	data->game.player = target;
	data->images.player->instances[0].x = target.x * TILE_SIZE;
	data->images.player->instances[0].y = target.y * TILE_SIZE;
}

static void	collectible_collect(t_data *data, t_coord target)
{
	mlx_instance_t	*instance;
	size_t			i;

	data->game.collectibles--;
	i = 0;
	target.x *= TILE_SIZE;
	target.y *= TILE_SIZE;
	while (i < data->images.collectible->count)
	{
		instance = &data->images.collectible->instances[i];
		if (instance->x == target.x && instance->y == target.y)
		{
			instance->enabled = false;
			break ;
		}
		i++;
	}
}

static t_coord	get_target_coord(t_data *data, keys_t key)
{
	t_coord	target;

	target = data->game.player;
	if (key == MLX_KEY_W)
		target.y--;
	else if (key == MLX_KEY_A)
		target.x--;
	else if (key == MLX_KEY_S)
		target.y++;
	else if (key == MLX_KEY_D)
		target.x++;
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
			data->game.movements++;
			ft_printf("Movements: %d\n", data->game.movements);
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
