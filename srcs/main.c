/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:59:12 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/02 13:24:34 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arguments_validate(int argc, char *argv[])
{
	char	*basename;

	if (argc < 2)
		print_error_exit("Missing map file argument");
	else if (argc > 2)
		print_error_exit("Too many arguments");
	if (ft_strrchr(argv[1], '/'))
		basename = ft_strrchr(argv[1], '/') + 1;
	else
		basename = argv[1];
	if (ft_strlen(basename) < 5)
		print_error_exit("Map file name too short");
	else if (!ft_strrchr(basename, '.'))
		print_error_exit("Missing map file extension");
	else if (ft_strcmp(ft_strrchr(basename, '.'), ".ber") != 0)
		print_error_exit("Invalid map file extension");
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
