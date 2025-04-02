/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:06:54 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/02 15:11:05 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	instances_set_depth(mlx_image_t *image, int zdepth)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		mlx_set_instance_depth(&image->instances[i], zdepth);
		i++;
	}
}

static void	images_set_depth(t_data *data)
{
	instances_set_depth(data->images.floor, 0);
	instances_set_depth(data->images.wall, 0);
	instances_set_depth(data->images.collectible, 1);
	instances_set_depth(data->images.exit, 1);
	instances_set_depth(data->images.player, 2);
}

static int	graphics_draw_tile(t_data *data, char type, int x, int y)
{
	int	ret;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	if (type == '0' || type == 'C' || type == 'E' || type == 'P')
		ret = mlx_image_to_window(data->mlx, data->images.floor, x, y);
	else if (type == '1')
		ret = mlx_image_to_window(data->mlx, data->images.wall, x, y);
	if (ret == -1)
		return (ret);
	if (type == 'C')
		ret = mlx_image_to_window(data->mlx, data->images.collectible, x, y);
	else if (type == 'E')
		ret = mlx_image_to_window(data->mlx, data->images.exit, x, y);
	else if (type == 'P')
		ret = mlx_image_to_window(data->mlx, data->images.player, x, y);
	return (ret);
}

void	graphics_draw_game(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->game.map_height)
	{
		x = 0;
		while (x < data->game.map_width)
		{
			if (graphics_draw_tile(data, data->game.map[y][x], x, y) == -1)
				cleanup_exit(data, NULL);
			x++;
		}
		y++;
	}
	images_set_depth(data);
}

void	images_create(t_data *data)
{
	mlx_t		*mlx;
	t_textures	textures;

	mlx = data->mlx;
	textures = data->textures;
	data->images.floor = mlx_texture_to_image(mlx, textures.floor);
	if (!data->images.floor)
		cleanup_exit(data, NULL);
	data->images.wall = mlx_texture_to_image(mlx, textures.wall);
	if (!data->images.wall)
		cleanup_exit(data, NULL);
	data->images.collectible = mlx_texture_to_image(mlx, textures.collectible);
	if (!data->images.collectible)
		cleanup_exit(data, NULL);
	data->images.exit = mlx_texture_to_image(mlx, textures.exit);
	if (!data->images.exit)
		cleanup_exit(data, NULL);
	data->images.player = mlx_texture_to_image(mlx, textures.player);
	if (!data->images.player)
		cleanup_exit(data, NULL);
}
