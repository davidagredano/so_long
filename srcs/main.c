/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:59:12 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 15:34:02 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (1);
	/* Crate and initialize game state */
	data.game = game_create(argv[1]);
	if (!data.game)
		return (EXIT_FAILURE);
	/* Create a window, load images and put them in the window */
	data.graphics = graphics_create(data.game);
	if (!data.graphics)
	{
		game_free(data.game);
		return (EXIT_FAILURE);
	}
	/* Draw the game initial state to the window */
	if (graphics_draw_game(data.graphics, data.game) == -1)
	{
		graphics_free(data.graphics);
		game_free(data.game);
		return (EXIT_FAILURE);
	}
	/* Setup hook */
	hooks_setup(&data);
	/* Start game loop */
	mlx_loop(data.graphics->mlx);
	/* Close the window and free all the images */
	graphics_free(data.graphics);
	/* Log game state in the terminal */
	log_game_state(data.game);
	/* Free game state data */
	game_free(data.game);
}
