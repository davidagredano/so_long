/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:43:26 by dagredan          #+#    #+#             */
/*   Updated: 2025/08/30 13:14:06 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 100

# include <fcntl.h>  // open
# include <stdlib.h> // EXIT_FAILURE
# include "MLX42/MLX42.h"
# include "libft.h"

typedef unsigned int	t_uint;

/* Coordinates */
typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

/* Images */
typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}		t_images;

/* Textures */
typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
}		t_textures;

/* Game */
typedef struct s_game
{
	int		map_width;
	int		map_height;
	char	**map;
	t_uint	collectibles;
	t_coord	exit;
	t_coord	player;
	t_uint	movements;
}		t_game;

/* Data */
typedef struct s_data
{
	t_game		game;
	mlx_t		*mlx;
	t_textures	textures;
	t_images	images;
}		t_data;

/* Game */
char	**map_create(t_data *data, char *filename);
int		map_count_rows(t_data *data, char *filename);
int		map_count_columns(t_data *data);
t_coord	map_entity_find(t_data *data, char entity);
t_uint	map_entity_count(t_data *data, char entity);
void	map_destroy(t_data *data);

/* Map validation */
void	map_check_shape(t_data *data);
void	map_check_characters(t_data *data);
void	map_check_valid_path(t_data *data, char *filename);

/* Graphics */
void	graphics_draw_game(t_data *data);
void	textures_load(t_data *data);
void	textures_destroy(t_data *data);
void	images_create(t_data *data);

/* Hooks */
void	hooks_setup(t_data *data);

/* Exit */
void	cleanup(t_data *data);
void	cleanup_exit(t_data *data, char *message);
void	print_error_exit(char *message);

#endif
