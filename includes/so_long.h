/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 08:43:26 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/26 12:06:31 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
	t_coord	*exit;
	t_coord	*player;
	int		collectibles;
	int		exit_enabled;
}		t_map;

/* Map */
t_map	*map_create(void);
void	map_free(t_map *map);

/* Exit */
t_coord	*exit_create(int x, int y);
void	exit_free(t_coord *exit);

/* Player */
t_coord	*player_create(int x, int y);
void	player_free(t_coord *player);

/* tmp */
void	map_log(t_map *map);

#endif
