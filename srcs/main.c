/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:59:12 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 22:16:11 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (game_init(&data.game, argv[1]) == -1)
		return (EXIT_FAILURE);
	data.graphics = graphics_create(&data.game);
	if (!data.graphics)
	{
		game_free(&data.game);
		return (EXIT_FAILURE);
	}
	if (graphics_draw_game(data.graphics, &data.game) == -1)
	{
		graphics_free(data.graphics);
		game_free(&data.game);
		return (EXIT_FAILURE);
	}
	hooks_setup(&data);
	mlx_loop(data.graphics->mlx);
	graphics_free(data.graphics);
	game_free(&data.game);
}
