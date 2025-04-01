/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:59:43 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/01 13:25:52 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_data *data, char *filename)
{
	data->game.map_height = map_count_rows(data, filename);
	data->game.map = map_create(data, filename);
	data->game.map_width = ft_strlen(data->game.map[0]);
	map_validate(data);
	data->game.collectibles = map_entity_count(data, 'C');
	data->game.exit = map_entity_find(data, 'E');
	data->game.player = map_entity_find(data, 'P');
	data->game.movements = 0;
}
