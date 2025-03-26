/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:43:34 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/26 11:24:05 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../includes/so_long.h"

t_coord	*player_create(int x, int y)
{
	t_coord	*player;

	player = (t_coord *)ft_calloc(1, sizeof(t_coord));
	if (!player)
		return (NULL);
	player->x = x;
	player->y = y;
	return (player);
}

void	player_free(t_coord *player)
{
	free(player);
}
