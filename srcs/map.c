/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:16:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/26 12:00:22 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../includes/so_long.h"

void	map_log(t_map *map)
{
	int	row;

	ft_printf("[L] Map (%dx%d):\n", map->width, map->height);
	ft_printf("[L]\n");
	row = 0;
	while (row < map->height)
	{
		ft_printf("[L]  %s\n", map->data[row]);
		row++;
	}
	ft_printf("[L]\n");
	ft_printf("[L] Entities   (x, y)\n");
	ft_printf("[L] Player '%c'", map->data[map->player->y][map->player->x]);
	ft_printf(" (%d, %d)\n", map->player->x, map->player->y);
	ft_printf("[L] Exit   '%c'", map->data[map->exit->y][map->exit->x]);
	ft_printf(" (%d, %d)\n", map->exit->x, map->exit->y);
	ft_printf("[L] Collectibles: %d\n", map->collectibles);
	ft_printf("[L] Exit enabled: %d\n", map->exit_enabled);
}

t_map	*map_create(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 7;
	map->height = 5;
	map->data = (char **)ft_calloc(5, sizeof(char *));
	if (!map->data)
		return (NULL);
	map->data[0] = ft_strdup("1111111"); // missing error protection
	map->data[1] = ft_strdup("1C000C1"); // missing error protection
	map->data[2] = ft_strdup("1000001"); // missing error protection
	map->data[3] = ft_strdup("1P000E1"); // missing error protection
	map->data[4] = ft_strdup("1111111"); // missing error protection
	map->exit = exit_create(5, 3); // missing error protection
	map->player = player_create(1, 3); // missing error protection
	map->collectibles = 2;
	map->exit_enabled = 0;
	return (map);
}

void	map_free(t_map *map)
{
	int	row;

	row = 0;
	if (map->data)
	{
		while (row < map->height)
		{
			if (map->data[row])
				free(map->data[row]);
			row++;
		}
		free(map->data);
	}
	if (map->exit)
		free(map->exit);
	if (map->player)
		free(map->player);
	free(map);
}
