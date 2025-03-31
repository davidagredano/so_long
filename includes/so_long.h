/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:43:26 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 21:33:02 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 100

# include <stdlib.h> // EXIT_FAILURE
# include "MLX42/MLX42.h"
# include "libft.h"

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
	int		collectibles;
	t_coord	exit;
	t_coord	player;
	int		movements;
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
int		game_init(t_game *game, char *filename);
void	game_free(t_game *game);

/* Map */
char	**map_create(t_game *game, char *filename);
t_coord	map_entity_find(t_game *game, char entity);
int		map_entity_count(t_game *game, char entity);
void	map_free(t_game *game);

/* Collectibles */
void	collectible_collect(t_data *data, t_coord target);

/* Player */
void	player_move(t_data *data, t_coord target);

/* Movements */
void	movements_add_one(t_game *game);
void	movements_log(t_game *game);

/* Graphics */
int		graphics_init(t_data *data);
int		graphics_draw_game(t_data *data);
void	graphics_free(t_data *data);

/* Textures */
int		textures_load(t_data *data);
void	textures_free(t_data *data);

/* Images */
int		images_create(t_data *data);

/* Hooks */
void	hooks_setup(t_data *data);

/* Debug */
void	log_game_state(t_game *game);

#endif
