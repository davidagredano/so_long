/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:49:11 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 15:34:46 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textures_free(t_data *data)
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

static int	textures_is_some_null(t_data *data)
{
	if (!data->textures.floor)
		return (1);
	if (!data->textures.wall)
		return (1);
	if (!data->textures.collectible)
		return (1);
	if (!data->textures.exit)
		return (1);
	if (!data->textures.player)
		return (1);
	return (0);
}

int	textures_load(t_data *data)
{
	data->textures.floor = mlx_load_png("./assets/floor.png");
	data->textures.wall = mlx_load_png("./assets/wall.png");
	data->textures.collectible = mlx_load_png("./assets/collectible.png");
	data->textures.exit = mlx_load_png("./assets/exit.png");
	data->textures.player = mlx_load_png("./assets/player.png");
	if (textures_is_some_null(data))
		return (-1);
	return (0);
}
