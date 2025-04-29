/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:09 by temil-da          #+#    #+#             */
/*   Updated: 2025/04/12 20:48:32 by temil-da         ###   ########.fr       */
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
	map[2] = ft_strdup("1000000001");
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
					for (int x = 0; x < TILE_SIZE; x++)
						for (int y = 0; y < TILE_SIZE; y++)
							mlx_put_pixel(game->image, col * TILE_SIZE + x, row * TILE_SIZE + y, 0x000000FF);
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
				px = (int)(game->player->x + x);
				py = (int)(game->player->y + y);
				mlx_put_pixel(game->image, px, py, 0xFF0000FF);
			}
		}
	}
}


void    handle_keystrokes(mlx_key_data_t data, void *param)
{
	t_game *game;
	
	game = (t_game *) param;
	if (data.action == MLX_PRESS)
	{
		if (data.key == MLX_KEY_ESCAPE)
		exit(0);
		game->keys[data.key] = true;
	}
	else if (data.action == MLX_RELEASE)
	game->keys[data.key] = false;
}

void    update_keystrokes(void *param)
{
	t_game	*game;
	bool	redraw;
	
	game = (t_game *) param;
	redraw = false;
	if (game->keys[MLX_KEY_W])
	move_player(game, game->player->dx * MOV_SPEED, game->player->dy * MOV_SPEED, &redraw);
	if (game->keys[MLX_KEY_A])
	move_player(game, game->player->dy * MOV_SPEED, -game->player->dx * MOV_SPEED, &redraw);
	if (game->keys[MLX_KEY_S])
	move_player(game, -game->player->dx * MOV_SPEED, -game->player->dy * MOV_SPEED, &redraw);
	if (game->keys[MLX_KEY_D])
	move_player(game, -game->player->dy * MOV_SPEED, game->player->dx * MOV_SPEED, &redraw);
	if (game->keys[MLX_KEY_LEFT] || game->keys[MLX_KEY_RIGHT])
	{
		if (game->keys[MLX_KEY_LEFT])
		game->player->angle -= ROT_SPEED;
		if (game->keys[MLX_KEY_RIGHT])
		game->player->angle += ROT_SPEED;
		if (game->player->angle < 0 || game->player->angle > TWO_PI)
		game->player->angle = norm_angle(game->player->angle);
		game->player->dx = cos(game->player->angle);
		game->player->dy = sin(game->player->angle);
		redraw = true;
	}
	if (redraw)
	{
		draw_map(game);
		draw_player(game);
		ray_caster(game);
	}
}

void	move_player(t_game *game, float dx, float dy, bool *redraw)
{
	game->player->x += dx;
	game->player->y += dy;
	if (game->map[(int)(game->player->y / TILE_SIZE)][(int)(game->player->x / TILE_SIZE)] == '1')
	{
		game->player->x -= dx;
		game->player->y -= dy;
		return ;
	}
	*redraw = true;
}	

void	init_player(t_player *player)
{
	player->x = 7 * TILE_SIZE + TILE_SIZE / 2;
	player->y = 2 * TILE_SIZE + TILE_SIZE / 2;
	player->angle = 3*PI/2;
	player->dx = cos(player->angle);
	player->dy = sin(player->angle);
}

float	norm_angle(float angle)
{
	if (angle < 0)
	angle += TWO_PI;
	else if (angle > TWO_PI)
	angle -= TWO_PI;
	return (angle);
}

void	free_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	draw_direction_line(t_game *game, float lenght)
{
	float	x;
	float	y;

	x = game->player->x;
	y = game->player->y;
	for (int i = 0; i < (int)lenght; i++)
	{
		x += game->player->dx;
		y += game->player->dy;
		mlx_put_pixel(game->image, (int)x, (int)y, 0xFF0000FF);
	}
}

void	ray_caster(t_game *game)
{
	int		map_x;
	int		map_y;
	float	delta_x;
	float	delta_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;

	map_x = (int)(game->player->x / TILE_SIZE);
	map_y = (int)(game->player->y / TILE_SIZE);
	delta_x = fabs(1 / game->player->dx);
	delta_y = fabs(1 / game->player->dy);
	if (game->player->dx < 0)
	{
		step_x = -1;
		side_dist_x = (game->player->x - map_x * TILE_SIZE) * delta_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = ((map_x + 1) * TILE_SIZE - game->player->x) * delta_x;
	}
	if (game->player->dy < 0)
	{
		step_y = -1;
		side_dist_y = (game->player->y - map_y * TILE_SIZE) * delta_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = ((map_y + 1) * TILE_SIZE - game->player->y) * delta_y;
	}
	while (game->map[map_y][map_x] != '1')
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_x;
			map_x += step_x;
		}
		else
		{
			side_dist_y += delta_y;
			map_y += step_y;
		}
	}
	// if (DEBUG_MODE)
	// 	draw_direction_line(game, lenght);
}