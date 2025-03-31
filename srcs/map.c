/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:16:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/31 11:11:32 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_init(t_game *game, char *filename)
{
	int	rows;

	(void)filename; // TODO Read data from map file
	rows = 7; // TODO Read data from map file
	game->map = (char **)ft_calloc(rows, sizeof(char *));
	if (!game->map)
		return (-1);
	game->map[0] = ft_strdup("1111111111111"); // missing err protection
	game->map[1] = ft_strdup("100000C000001"); // missing err protection
	game->map[2] = ft_strdup("1000C000C0001"); // missing err protection
	game->map[3] = ft_strdup("10P000C000E01"); // missing err protection
	game->map[4] = ft_strdup("1000C000C0001"); // missing err protection
	game->map[5] = ft_strdup("100000C000001"); // missing err protection
	game->map[6] = ft_strdup("1111111111111"); // missing err protection
	game->map_height = rows;
	game->map_width = ft_strlen(game->map[0]);
	return (0);
}

void	map_free(t_game *game)
{
	int	row;

	row = 0;
	while (row < game->map_height)
	{
		if (game->map[row])
			free(game->map[row]);
		row++;
	}
	free(game->map);
	game->map = NULL;
}
