/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:09 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 20:48:07 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_collect(t_data *data, t_coord target)
{
	mlx_instance_t	*instance;
	size_t			i;

	data->game.collectibles--;
	i = 0;
	target.x *= TILE_SIZE;
	target.y *= TILE_SIZE;
	while (i < data->images.collectible->count)
	{
		instance = &data->images.collectible->instances[i];
		if (instance->x == target.x && instance->y == target.y)
		{
			instance->enabled = false;
			break ;
		}
		i++;
	}
}
