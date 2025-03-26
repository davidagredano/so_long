/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:16:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/26 18:03:59 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../includes/so_long.h"

void	map_log(void *param)
{
	int		row;
	int		column;
	t_map	*map;

	map = (t_map *)param;
	system("clear");
	ft_printf("[L] Map (%dx%d):\n", map->width, map->height);
	ft_printf("[L]\n");
	row = 0;
	while (row < map->height)
	{
		column = 0;
		while (map->data[row][column] != '\0')
		{
			if (map->data[row][column] == '0')
				map->data[row][column] = ' ';
			column++;
		}
		ft_printf("[L]  %s\n", map->data[row]);
		column = 0;
		while (map->data[row][column] != '\0')
		{
			if (map->data[row][column] == ' ')
				map->data[row][column] = '0';
			column++;
		}
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
	ft_printf("Movements: %d\n", map->movements);
}

t_map	*map_create(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = 13;
	map->height = 7;
	map->data = (char **)ft_calloc(map->height, sizeof(char *));
	if (!map->data)
		return (NULL);
	map->data[0] = ft_strdup("1111111111111"); // missing error protection
	map->data[1] = ft_strdup("1000000000001"); // missing error protection
	map->data[2] = ft_strdup("1000C000C0001"); // missing error protection
	map->data[3] = ft_strdup("10P000C000E01"); // missing error protection
	map->data[4] = ft_strdup("1000C000C0001"); // missing error protection
	map->data[5] = ft_strdup("1000000000001"); // missing error protection
	map->data[6] = ft_strdup("1111111111111"); // missing error protection
	map->exit = exit_create(10, 3); // missing error protection
	map->player = player_create(2, 3); // missing error protection
	map->collectibles = 5;
	map->exit_enabled = 0;
	map->movements = 0;
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
