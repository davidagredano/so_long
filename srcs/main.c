/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:59:12 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/01 08:54:24 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arguments_validate(int argc, char *argv[])
{
	if (argc < 2)
	{
		print_error("Missing map file argument");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		print_error("Too many arguments");
		exit(EXIT_FAILURE);
	}
	else if (ft_strlen(argv[1]) < 5)
	{
		print_error("Map file name too short");
		exit(EXIT_FAILURE);
	}
	else if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
	{
		print_error("Invalid map file extension");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	arguments_validate(argc, argv);
	ft_bzero(&data, sizeof(t_data));
	game_init(&data, argv[1]);
	graphics_init(&data);
	graphics_draw_game(&data);
	hooks_setup(&data);
	mlx_loop(data.mlx);
	cleanup(&data);
}
