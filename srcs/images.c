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

static void	images_free(mlx_t *mlx, t_images *images)
{
	if (images->player)
		mlx_delete_image(mlx, images->player);
	free(images);
}

t_images	*images_create(mlx_t *mlx)
{
	t_textures	*textures;
	t_images	*images;

	textures = textures_load();
	if (!textures)
	{
		textures_free(textures);
		return (NULL);
	}
	images = textures_to_images(mlx, textures);
	if (!images)
	{
		textures_free(textures);
		images_free(mlx, images);
		return (NULL);
	}
	textures_free(textures);
	return (images);
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

void	images_set_depth(t_images *images)
{
	instances_set_depth(images->floor, 0);
	instances_set_depth(images->wall, 0);
	instances_set_depth(images->collectible, 1);
	instances_set_depth(images->exit, 1);
	instances_set_depth(images->player, 2);
}
