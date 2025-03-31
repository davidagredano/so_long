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

char	**map_create(t_game *game, char *filename)
{
	char	**map;

	(void)filename; // TODO Read data from map file
	map = (char **)ft_calloc(game->map_height, sizeof(char *));
	if (!map)
		return (NULL);
	map[0] = ft_strdup("1111111111111"); // missing err protection
	map[1] = ft_strdup("100000C000001"); // missing err protection
	map[2] = ft_strdup("1000C000C0001"); // missing err protection
	map[3] = ft_strdup("10P000C000E01"); // missing err protection
	map[4] = ft_strdup("1000C000C0001"); // missing err protection
	map[5] = ft_strdup("100000C000001"); // missing err protection
	map[6] = ft_strdup("1111111111111"); // missing err protection
	return (map);
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

t_coord	map_entity_find(t_game *game, char type)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < game->map_height)
	{
		coord.x = 0;
		while (coord.x < game->map_width)
		{
			if (game->map[coord.y][coord.x] == type)
				return (coord);
			coord.x++;
		}
		coord.y++;
	}
	coord.x = -1;
	coord.y = -1;
	return (coord);
}

int	map_entity_count(t_game *game, char type)
{
	int		count;
	t_coord	coord;

	count = 0;
	coord.y = 0;
	while (coord.y < game->map_height)
	{
		coord.x = 0;
		while (coord.x < game->map_width)
		{
			if (game->map[coord.y][coord.x] == type)
				count++;
			coord.x++;
		}
		coord.y++;
	}
	return (count);
}
