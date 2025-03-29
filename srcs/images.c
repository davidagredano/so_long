/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:06:54 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 00:45:45 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "libft.h"
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
