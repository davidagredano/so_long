/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:36:53 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/02 13:58:56 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graphics_init(t_data *data)
{
	int			width;
	int			height;

	width = data->game.map_width * TILE_SIZE;
	height = data->game.map_height * TILE_SIZE;
	data->mlx = mlx_init(width, height, "so_long", true);
	if (!data->mlx)
		cleanup_exit(data, NULL);
	textures_load(data);
	images_create(data);
}

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
