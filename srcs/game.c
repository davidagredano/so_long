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
	if (map_init(game, filename) == -1)
	{
		game_free(game);
		return (-1);
	}
	collectibles_init(game);
	exit_init(game);
	player_init(game);
	movements_init(game);
	return (0);
}

void	game_free(t_game *game)
{
	if (game->map)
		map_free(game);
}
