/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:16:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/26 17:48:10 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../includes/so_long.h"

t_data	*data_create(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = map_create(); // missing error check
	data->mlx = mlx_init(300, 300, "so_long", true); // missing error check
	return (data);
}

void	data_free(t_data *data)
{
	if (data->map)
		map_free(data->map);
	if (data->mlx)
		mlx_terminate(data->mlx);
	free(data);
}
