/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:43:26 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/27 16:33:40 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"

# include <stdlib.h> // EXIT_FAILURE

/* Graphics */
typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}		t_images;

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
}		t_textures;

typedef struct s_graphics
{
	t_textures	textures;
	t_images	images;
}		t_graphics;

/* Game */
typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_exit
{
	int	x;
	int	y;
	int	enabled;
}		t_exit;

typedef struct s_tilemap
{
	int		width;
	int		height;
	char	**map;
}		t_tilemap;

typedef struct s_game
{
	t_tilemap	tilemap;
	int			collectibles;
	t_exit		exit;
	t_player	player;
	int			movements;
}		t_game;

/* Game */
t_game	*game_create(char *filename);
void	game_free(t_game *game);

/* Tilemap */
int		tilemap_init(t_game *game, char *filename);
void	map_free(char **map, int height);

/* Collectibles */
void	collectibles_init(t_game *game);

/* Exit */
void	exit_init(t_game *game);

/* Player */
void	player_init(t_game *game);

/* Movements */
void	movements_init(t_game *game);

/* Debug */
void	log_game_state(t_game *game);

#endif
