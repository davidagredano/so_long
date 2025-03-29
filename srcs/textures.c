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

void	textures_free(t_textures *textures)
{
	if (textures->floor)
		mlx_delete_texture(textures->floor);
	if (textures->wall)
		mlx_delete_texture(textures->wall);
	if (textures->collectible)
		mlx_delete_texture(textures->collectible);
	if (textures->exit)
		mlx_delete_texture(textures->exit);
	if (textures->player)
		mlx_delete_texture(textures->player);
	free(textures);
}

t_textures	*textures_load(void)
{
	t_textures	*textures;

	textures = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->floor = mlx_load_png("./assets/floor.png");
	if (!textures->floor)
		return (NULL);
	textures->wall = mlx_load_png("./assets/wall.png");
	if (!textures->wall)
		return (NULL);
	textures->collectible = mlx_load_png("./assets/collectible.png");
	if (!textures->collectible)
		return (NULL);
	textures->exit = mlx_load_png("./assets/exit.png");
	if (!textures->exit)
		return (NULL);
	textures->player = mlx_load_png("./assets/player.png");
	if (!textures->player)
		return (NULL);
	return (textures);
}

t_images	*textures_to_images(mlx_t *mlx, t_textures *textures)
{
	t_images	*images;

	images = (t_images *)ft_calloc(1, sizeof(t_images));
	if (!images)
		return (NULL);
	images->floor = mlx_texture_to_image(mlx, textures->floor);
	if (!images->floor)
		return (NULL);
	images->wall = mlx_texture_to_image(mlx, textures->wall);
	if (!images->wall)
		return (NULL);
	images->collectible = mlx_texture_to_image(mlx, textures->collectible);
	if (!images->collectible)
		return (NULL);
	images->exit = mlx_texture_to_image(mlx, textures->exit);
	if (!images->exit)
		return (NULL);
	images->player = mlx_texture_to_image(mlx, textures->player);
	if (!images->player)
		return (NULL);
	return (images);
}
