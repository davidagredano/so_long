/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:12:21 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/29 21:42:43 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movements_init(t_game *game)
{
	game->movements = 0;
}

void	movements_add_one(t_game *game)
{
	game->movements++;
}

void	movements_log(t_game *game)
{
	ft_printf("Movements: %d\n", game->movements);
}
