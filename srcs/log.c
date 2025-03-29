#include "so_long.h"

void	log_game_state(t_game *game)
{
	char	**map;
	int		row;
	int		column;

	map = game->tilemap.map;
	ft_printf("[L] Map (%dx%d):\n", game->tilemap.width, game->tilemap.height);
	ft_printf("[L]\n");
	row = 0;
	while (row < game->tilemap.height)
	{
		column = 0;
		while (map[row][column] != '\0')
		{
			if (map[row][column] == '0')
				map[row][column] = ' ';
			column++;
		}
		ft_printf("[L]  %s\n", map[row]);
		column = 0;
		while (map[row][column] != '\0')
		{
			if (map[row][column] == ' ')
				map[row][column] = '0';
			column++;
		}
		row++;
	}
	ft_printf("[L]\n");
	ft_printf("[L] Entities   (x, y)\n");
	ft_printf("[L] Exit   '%c'", map[game->exit.y][game->exit.x]);
	ft_printf(" (%d, %d)\n", game->exit.x, game->exit.y);
	ft_printf("[L] Player '%c'", map[game->player.y][game->player.x]);
	ft_printf(" (%d, %d)\n", game->player.x, game->player.y);
	ft_printf("[L] Collectibles: %d\n", game->collectibles);
	ft_printf("[L] Exit enabled: %d\n", game->exit.enabled);
	ft_printf("Movements: %d\n", game->movements);
}
