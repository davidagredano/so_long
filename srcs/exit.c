/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:43:34 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/26 11:39:15 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../includes/so_long.h"

t_coord	*exit_create(int x, int y)
{
	t_coord	*exit;

	exit = (t_coord *)ft_calloc(1, sizeof(t_coord));
	if (!exit)
		return (NULL);
	exit->x = x;
	exit->y = y;
	return (exit);
}

void	exit_free(t_coord *exit)
{
	free(exit);
}
