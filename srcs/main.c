/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:59:12 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/02 15:11:31 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	graphics_init(t_data *data)
{
	int			width;
	int			height;

	width = data->game.map_width * TILE_SIZE;
	height = data->game.map_height * TILE_SIZE;
	data->mlx = mlx_init(width, height, "so_long", true);
	if (!data->mlx)
		cleanup_exit(data, NULL);
	textures_load(data);
	images_create(data);
}

char	**map_create(t_data *data, char *filename)
{
	char	**map;
	char	*row;
	int		fd;
	int		i;

	map = (char **)ft_calloc(data->game.map_height, sizeof(char *));
	if (!map)
		cleanup_exit(data, "Failed to allocate memory for map");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		cleanup_exit(data, "Failed to open map file");
	i = 0;
	while (i < data->game.map_height)
	{
		row = get_next_line(fd);
		if (!row)
			cleanup_exit(data, "Failed to read map file");
		if (ft_strlen(row) > 0 && row[ft_strlen(row) - 1] == '\n')
			row[ft_strlen(row) - 1] = '\0';
		map[i] = row;
		i++;
	}
	if (close(fd) == -1)
		cleanup_exit(data, "Failed to close map file");
	return (map);
}

static void	game_init(t_data *data, char *filename)
{
	data->game.map_height = map_count_rows(data, filename);
	data->game.map = map_create(data, filename);
	data->game.map_width = map_count_columns(data);
	map_validate(data, filename);
	data->game.collectibles = map_entity_count(data, 'C');
	data->game.exit = map_entity_find(data, 'E');
	data->game.player = map_entity_find(data, 'P');
	data->game.movements = 0;
}

static void	arguments_validate(int argc, char *argv[])
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
