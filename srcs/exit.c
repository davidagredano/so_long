/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:43:34 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 00:22:25 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_init(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->tilemap.map;
	y = 0;
	while (y < game->tilemap.height)
	{
		x = 0;
		while (x < game->tilemap.width)
		{
			if (map[y][x] == 'E')
			{
				game->exit.x = x;
				game->exit.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
	game->exit.enabled = 0;
}
