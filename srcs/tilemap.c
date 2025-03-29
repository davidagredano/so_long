/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:16:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 19:43:45 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	tilemap_init(t_game *game, char *filename)
{
	int	rows;

	(void)filename; // TODO Read data from map file
	rows = 7; // TODO Read data from map file
	game->tilemap.map = (char **)ft_calloc(rows, sizeof(char *));
	if (!game->tilemap.map)
		return (-1);
	game->tilemap.map[0] = ft_strdup("1111111111111"); // missing err protection
	game->tilemap.map[1] = ft_strdup("100000C000001"); // missing err protection
	game->tilemap.map[2] = ft_strdup("1000C000C0001"); // missing err protection
	game->tilemap.map[3] = ft_strdup("10P000C000E01"); // missing err protection
	game->tilemap.map[4] = ft_strdup("1000C000C0001"); // missing err protection
	game->tilemap.map[5] = ft_strdup("100000C000001"); // missing err protection
	game->tilemap.map[6] = ft_strdup("1111111111111"); // missing err protection
	game->tilemap.height = rows;
	game->tilemap.width = ft_strlen(game->tilemap.map[0]);
	return (0);
}

void	map_free(char **map, int height)
{
	int	row;

	row = 0;
	while (row < height)
	{
		if (map[row])
			free(map[row]);
		row++;
	}
	free(map);
}
