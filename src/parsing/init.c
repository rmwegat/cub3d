/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rwegat <rwegat@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/30 15:13:30 by rwegat			#+#	#+#			 */
/*   Updated: 2025/04/30 18:44:05 by rwegat		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_path_check(char **map, int x, int y)
{
	if (y < 0 || map[y] == NULL || x < 0 || \
		map[y][x] == '\0' || map[y][x] == '\n')
	{
		perror("Error: Map is not enclosed by walls!\n");
		exit(1);
	}
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == ' ')
	{
		perror("Error: Map is not enclosed by walls!\n");
		exit(1);
	}
	if (map[y][x] == '0')
	{
		map[y][x] = 'V';
		ft_path_check(map, x + 1, y);
		ft_path_check(map, x - 1, y);
		ft_path_check(map, x, y + 1);
		ft_path_check(map, x, y - 1);
	}
}

int	is_map_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != ' ' && map[i][j] != '\n')
				return (ft_printf("Error: Invalid character in map!\n"));
			j++;
		}
		i++;
	}
	return (0);
}

int	init_player(t_game *game)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E' ||
				game->map[i][j] == 'S' || game->map[i][j] == 'W')
			{
				player_count++;
				game->starting_direction = game->map[i][j];
				game->map[i][j] = '0';
				game->player->x = (float)j * TILE_SIZE + TILE_SIZE / 2;
				game->player->y = (float)i * TILE_SIZE + TILE_SIZE / 2;
			}
			j++;
		}
		i++;
	}
	return (player_count);
}

char	**copy_map(char **map)
{
	int		i;
	int		rows;
	char	**map_copy;

	rows = 0;
	while (map[rows])
		rows++;
	map_copy = malloc((rows + 1) * sizeof(char *));
	if (!map_copy)
		exit(1);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			exit(1);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	init(t_game *game)
{
	char	**map_copy;

	if (!game)
		return ;
	if (init_player(game) != 1)
	{
		ft_printf("Error: Invalid amount of players found!\n");
		exit(1);
	}
	if (game->starting_direction == 'N')
		game->player->angle = 3 * PI / 2;
	else if (game->starting_direction == 'E')
		game->player->angle = 0;
	else if (game->starting_direction == 'S')
		game->player->angle = PI / 2;
	else if (game->starting_direction == 'W')
		game->player->angle = PI;
	game->player->dx = cos(game->player->angle);
	game->player->dy = sin(game->player->angle);
	map_copy = copy_map(game->map);
	ft_path_check(map_copy, (int)(game->player->x / TILE_SIZE), \
	(int)(game->player->y / TILE_SIZE));
	ft_free_map(&map_copy);
	is_map_valid(game->map);
}
