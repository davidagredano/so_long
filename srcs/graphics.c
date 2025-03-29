/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 22:36:53 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 15:34:34 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graphics	*graphics_create(t_game *game)
{
	t_graphics	*graphics;

	graphics = (t_graphics *)ft_calloc(1, sizeof(t_graphics));
	if (!graphics)
		return (NULL);
	graphics->mlx = mlx_init(game->tilemap.width * TILE_SIZE,
			game->tilemap.height * TILE_SIZE, "so_long", true);
	if (!graphics->mlx)
	{
		graphics_free(graphics);
		return (NULL);
	}
	graphics->images = images_create(graphics->mlx);
	if (!graphics->images)
	{
		graphics_free(graphics);
		return (NULL);
	}
	return (graphics);
}

void	graphics_free(t_graphics *graphics)
{
	if (graphics->mlx)
		mlx_terminate(graphics->mlx);
	if (graphics->images)
		free(graphics->images);
	free(graphics);
}

static int	graphics_draw_tile(t_graphics *graphics, char tile, int x, int y)
{
	int	ret;

	if (tile == '0' || tile == 'C' || tile == 'E' || tile == 'P')
		ret = mlx_image_to_window(graphics->mlx, graphics->images->floor,
				x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == '1')
		ret = mlx_image_to_window(graphics->mlx, graphics->images->wall,
				x * TILE_SIZE, y * TILE_SIZE);
	if (tile == 'C')
		ret = mlx_image_to_window(graphics->mlx, graphics->images->collectible,
				x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		ret = mlx_image_to_window(graphics->mlx, graphics->images->exit,
				x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		ret = mlx_image_to_window(graphics->mlx, graphics->images->player,
				x * TILE_SIZE, y * TILE_SIZE);
	return (ret);
}

int	graphics_draw_game(t_graphics *graphics, t_game *game)
{
	char		**map;
	int			x;
	int			y;

	map = game->tilemap.map;
	y = 0;
	while (y < game->tilemap.height)
	{
		x = 0;
		while (x < game->tilemap.width)
		{
			if (graphics_draw_tile(graphics, map[y][x], x, y) == -1)
				return (-1);
			x++;
		}
		y++;
	}
	images_set_depth(graphics->images);
	return (0);
}
