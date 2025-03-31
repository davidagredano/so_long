/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:49:11 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/31 19:12:22 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textures_destroy(t_data *data)
{
	if (data->textures.floor)
		mlx_delete_texture(data->textures.floor);
	if (data->textures.wall)
		mlx_delete_texture(data->textures.wall);
	if (data->textures.collectible)
		mlx_delete_texture(data->textures.collectible);
	if (data->textures.exit)
		mlx_delete_texture(data->textures.exit);
	if (data->textures.player)
		mlx_delete_texture(data->textures.player);
	data->textures.floor = NULL;
	data->textures.wall = NULL;
	data->textures.collectible = NULL;
	data->textures.exit = NULL;
	data->textures.player = NULL;
}

void	textures_load(t_data *data)
{
	data->textures.floor = mlx_load_png("./assets/floor.png");
	if (!data->textures.floor)
		cleanup_exit(data, NULL);
	data->textures.wall = mlx_load_png("./assets/wall.png");
	if (!data->textures.wall)
		cleanup_exit(data, NULL);
	data->textures.collectible = mlx_load_png("./assets/collectible.png");
	if (!data->textures.collectible)
		cleanup_exit(data, NULL);
	data->textures.exit = mlx_load_png("./assets/exit.png");
	if (!data->textures.exit)
		cleanup_exit(data, NULL);
	data->textures.player = mlx_load_png("./assets/player.png");
	if (!data->textures.player)
		cleanup_exit(data, NULL);
}
