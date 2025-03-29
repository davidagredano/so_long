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

/* Game */
typedef struct s_coord
{
	int	x;
	int	y;
}			t_coord;

typedef struct s_tilemap
{
	int		width;
	int		height;
	char	**map;
}			t_tilemap;

typedef struct s_game
{
	t_tilemap	tilemap;
	int			collectibles;
	t_coord		exit;
	t_coord		player;
	int			movements;
}			t_game;

/* Graphics */
typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
}			t_textures;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}			t_images;

typedef struct s_graphics
{
	mlx_t		*mlx;
	t_images	*images;
}			t_graphics;

/* Data */
typedef struct s_data
{
	t_game		*game;
	t_graphics	*graphics;
}			t_data;

/* Game */
t_game		*game_create(char *filename);
void		game_free(t_game *game);

/* Tilemap */
int			tilemap_init(t_game *game, char *filename);
void		map_free(char **map, int height);
char		tilemap_get_target_tile(t_game *game, keys_t key);

/* Collectibles */
void		collectibles_init(t_game *game);
void		collectible_collect(t_data *data, t_coord target);

/* Exit */
void		exit_init(t_game *game);

/* Player */
void		player_init(t_game *game);
void		player_move(t_data *data, t_coord target);

/* Movements */
void		movements_init(t_game *game);
void		movements_add_one(t_game *game);
void		movements_log(t_game *game);

/* Graphics */
t_graphics	*graphics_create(t_game *game);
int			graphics_draw_game(t_graphics *graphics, t_game *game);
void		graphics_free(t_graphics *graphics);

/* Textures */
t_textures	*textures_load(void);
t_images	*textures_to_images(mlx_t *mlx, t_textures *textures);
void		textures_free(t_textures *textures);

/* Images */
t_images	*images_create(mlx_t *mlx);
void		images_set_depth(t_images *images);

/* Hooks */
void		hooks_setup(t_data *data);

/* Debug */
void		log_game_state(t_game *game);

#endif
