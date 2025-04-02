/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:19:51 by dagredan          #+#    #+#             */
/*   Updated: 2025/04/02 15:10:53 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error_exit(char *message)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("so_long: ", STDERR_FILENO);
	if (mlx_errno > 0)
	{
		ft_putstr_fd("MLX42: ", STDERR_FILENO);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	}
	else
		ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	cleanup(t_data *data)
{
	if (data->mlx)
	{
		mlx_terminate(data->mlx);
		data->mlx = NULL;
	}
	textures_destroy(data);
	if (data->game.map)
		map_destroy(data);
}

void	cleanup_exit(t_data *data, char *message)
{
	cleanup(data);
	print_error_exit(message);
}
