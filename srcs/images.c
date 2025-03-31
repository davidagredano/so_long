/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:06:54 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 15:35:08 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	images_is_some_null(t_data *data)
{
	if (!data->images.floor)
		return (1);
	if (!data->images.wall)
		return (1);
	if (!data->images.collectible)
		return (1);
	if (!data->images.exit)
		return (1);
	if (!data->images.player)
		return (1);
	return (0);
}

int	images_create(t_data *data)
{
	mlx_t		*mlx;
	t_textures	textures;

	mlx = data->mlx;
	textures = data->textures;
	data->images.floor = mlx_texture_to_image(mlx, textures.floor);
	data->images.wall = mlx_texture_to_image(mlx, textures.wall);
	data->images.collectible = mlx_texture_to_image(mlx, textures.collectible);
	data->images.exit = mlx_texture_to_image(mlx, textures.exit);
	data->images.player = mlx_texture_to_image(mlx, textures.player);
	if (images_is_some_null(data))
		return (-1);
	return (0);
}
