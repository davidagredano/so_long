/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:59:12 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/31 19:11:58 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (EXIT_FAILURE);
	ft_bzero(&data, sizeof(t_data));
	game_init(&data.game, argv[1]);
	graphics_init(&data);
	graphics_draw_game(&data);
	hooks_setup(&data);
	mlx_loop(data.mlx);
	cleanup(&data);
}
