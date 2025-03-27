/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:59:43 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/27 15:35:24 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../includes/so_long.h"

t_game	*game_create(char *filename)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	if (tilemap_init(game, filename) == -1)
	{
		game_free(game);
		return (NULL);
	}
	collectibles_init(game);
	exit_init(game);
	player_init(game);
	movements_init(game);
	return (game);
}

void	game_free(t_game *game)
{
	if (game->tilemap.map)
		map_free(game->tilemap.map, game->tilemap.height);
	free(game);
}
