#include "so_long.h"

void	log_game_state(t_game *game)
{
	int		row;
	int		column;

	ft_printf("[L] Map (%dx%d):\n", game->map_width, game->map_height);
	ft_printf("[L]\n");
	row = 0;
	while (row < game->map_height)
	{
		column = 0;
		while (game->map[row][column] != '\0')
		{
			if (game->map[row][column] == '0')
				game->map[row][column] = ' ';
			column++;
		}
		ft_printf("[L]  %s\n", game->map[row]);
		column = 0;
		while (game->map[row][column] != '\0')
		{
			if (game->map[row][column] == ' ')
				game->map[row][column] = '0';
			column++;
		}
		row++;
	}
	ft_printf("[L]\n");
	ft_printf("[L] Entities   (x, y)\n");
	ft_printf("[L] Exit   '%c'", game->map[game->exit.y][game->exit.x]);
	ft_printf(" (%d, %d)\n", game->exit.x, game->exit.y);
	ft_printf("[L] Player '%c'", game->map[game->player.y][game->player.x]);
	ft_printf(" (%d, %d)\n", game->player.x, game->player.y);
	ft_printf("[L] Collectibles: %d\n", game->collectibles);
	ft_printf("Movements: %d\n", game->movements);
}
