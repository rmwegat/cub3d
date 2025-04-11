/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:09 by temil-da          #+#    #+#             */
/*   Updated: 2025/04/11 16:59:19 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
		}

char	**init_map()
{
	char	**map;

	map = malloc(8 * sizeof(char *));
	map[0] = ft_strdup("1111111111");
	map[1] = ft_strdup("1000000001");
	map[2] = ft_strdup("1000000N01");
	map[3] = ft_strdup("1000000001");
	map[4] = ft_strdup("1001000101");
	map[5] = ft_strdup("1000000001");
	map[6] = ft_strdup("1111111111");
	map[7] = NULL;
	return (map);
}

	void	draw_map(t_game *game)
	{
		int	start_x;
		int	start_y;
		int	row;
		int	col;

		row = 0;
		while (game->map[row])
		{	
			col = 0;
			while(game->map[row][col])
			{
				start_x = col * TILE_SIZE;
				start_y = row * TILE_SIZE;
				if (game->map[row][col] == '1')
				{
					for (int x = 0; x < TILE_SIZE; x++)
						for (int y = 0; y < TILE_SIZE; y++)
							mlx_put_pixel(game->image, col * TILE_SIZE + x, row * TILE_SIZE + y, 0x00FF00FF);
				}
				else
				{
					for (int i = 0; i < TILE_SIZE; i++)
						mlx_put_pixel(game->image, start_x + i, start_y, 0xFFFFFFFF);
					for (int i = 0; i < TILE_SIZE; i++)
						mlx_put_pixel(game->image, start_x + i, start_y + TILE_SIZE - 1, 0xFFFFFFFF);
					for (int i = 0; i < TILE_SIZE; i++)
						mlx_put_pixel(game->image, start_x, start_y + i, 0xFFFFFFFF);
					for (int i = 0; i < TILE_SIZE; i++)
						mlx_put_pixel(game->image, start_x + TILE_SIZE - 1, start_y + i, 0xFFFFFFFF);
				}
				col++;
			}
			row++;
		}
	}

void	draw_player(t_game *game)
{
	int	radius;
	int	px;
	int	py;

	radius = 3;
	for (int y = -radius; y <= radius; y++)
	{
		for (int x = -radius; x <= radius; x++)
		{
			if (x * x + y * y <= radius * radius)
			{
				px = (int)(game->player_x + x);
				py = (int)(game->player_y + y);
				mlx_put_pixel(game->image, px, py, 0xFF0000FF);
			}
		}
	}
}