/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:59:43 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 15:34:20 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_init(t_game *game, char *filename)
{
	game->map_height = 7; // TODO Get from map file
	game->map = map_create(game, filename);
	if (!game->map)
	{
		game_free(game);
		return (-1);
	}
	game->map_width = ft_strlen(game->map[0]);
	game->collectibles = map_entity_count(game, 'C');
	game->exit = map_entity_find(game, 'E');
	game->player = map_entity_find(game, 'P');
	game->movements = 0;
	return (0);
}

void	game_free(t_game *game)
{
	if (game->map)
		map_free(game);
}
