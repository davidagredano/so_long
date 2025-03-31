/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:06:54 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/31 19:11:49 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
