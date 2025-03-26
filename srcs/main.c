/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:59:12 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/26 19:02:39 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../includes/so_long.h"

static void	game_update(char key, t_map *map, mlx_t *mlx)
{
	t_coord	target;

	target.x = map->player->x;
	target.y = map->player->y;
	if (key == 'W')
		target.y -= 1;
	else if (key == 'A')
		target.x -= 1;
	else if (key == 'S')
		target.y += 1;
	else if (key == 'D')
		target.x += 1;
	if (map->data[target.y][target.x] != '1')
	{
		if (map->data[target.y][target.x] == 'C')
			map->collectibles -= 1;
		else if (map->data[target.y][target.x] == 'E' && map->exit_enabled == 1)
			mlx_close_window(mlx);
		map->data[target.y][target.x] = 'P';
		if (map->player->x == map->exit->x && map->player->y == map->exit->y)
			map->data[map->player->y][map->player->x] = 'E';
		else
			map->data[map->player->y][map->player->x] = '0';
		map->player->x = target.x;
		map->player->y = target.y;
		map->movements += 1;
	}
	if (map->collectibles == 0)
		map->exit_enabled = 1;
}

static void	key_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_W))
			game_update('W', data->map, data->mlx);
		else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
			game_update('A', data->map, data->mlx);
		else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
			game_update('S', data->map, data->mlx);
		else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
			game_update('D', data->map, data->mlx);
		map_log(data->map);
		usleep(250000);
	}
}

int	main(void)
{
	t_data	*data;

	data = data_create(); // missing error check
	map_log(data->map);
	mlx_loop_hook(data->mlx, key_hook, data);
	mlx_loop(data->mlx);
	data_free(data);
}
