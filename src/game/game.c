/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:09 by temil-da          #+#    #+#             */
/*   Updated: 2025/04/30 19:41:59 by temil-da         ###   ########.fr       */
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

void    update_keystrokes(void *param)
{
	t_game	*game;
	bool	redraw;
	
	game = (t_game *) param;
	redraw = false;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, game->player->dx * MOV_SPEED, game->player->dy * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, game->player->dy * MOV_SPEED, -game->player->dx * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, -game->player->dx * MOV_SPEED, -game->player->dy * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, -game->player->dy * MOV_SPEED, game->player->dx * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
			game->player->angle -= ROT_SPEED;
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
			game->player->angle += ROT_SPEED;
		norm_angle(&game->player->angle);
		game->player->dx = cos(game->player->angle);
		game->player->dy = sin(game->player->angle);
		redraw = true;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		exit (0);
	if (redraw)
	{
		draw_map(game);
		draw_player(game);
		draw_rays(game);
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

void	norm_angle(float *angle)
{
	if (*angle < 0)
	*angle += TWO_PI;
	else if (*angle > TWO_PI)
	*angle -= TWO_PI;
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

void	draw_rays(t_game *game)
{
	float	start;
	float	ray_angle;
	float	ray_step;

	start = game->player->angle - (FOV / 2);
	ray_step = FOV / WIDTH;
	for (int i = 0; i < WIDTH; i++)
	{
		ray_angle = start + i * ray_step;
		ray_caster(game, ray_angle);
	}
}

void	ray_caster(t_game *game, float angle)
{
	int		map_x;
	int		map_y;
	float	dx;
	float	dy;
	float	delta_x;
	float	delta_y;
	int		step_x;		//STEPX, STEPY, THE DIRECTION WE ARE STEPPING ON THE X/Y AXIS (POSITIVE OR NEGATIVE)
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	float	distance;

	dx = cos(angle);
	dy = sin(angle);
	map_x = (int)(game->player->x / TILE_SIZE);
	map_y = (int)(game->player->y / TILE_SIZE);
	delta_x = sqrt(1 + (dy / dx) * (dy / dx)); // THIS CALCULATION TELLS US THE DISTANCE WE NEED TO TRAVEL IN OUR RAY DIRECTION TO TRAVEL ONE UNIT OF X OR Y
	delta_y = sqrt(1 + (dx / dy) * (dx / dy));
	if (dx < 0)
	{
		step_x = -1;
		side_dist_x = (game->player->x - (float)(map_x * TILE_SIZE)) * delta_x; // IN THIS STEP WE ARE SETTING OUR STEP_X AND STEP_Y TO A NEGATIVE OR POSITIVE 1 DEPENDING ON THE DIRECTION AND WE FIND OUT THE DISTANCE OF THE RAY FOR THE CURRENT STARTING CELL
	}																				// SO THAT WE CAN START THE ALGORIGHM LOOP
	else
	{
		step_x = 1;
		side_dist_x = ((float)(map_x + 1) * (float)TILE_SIZE - game->player->x) * delta_x;
	}
	if (dy < 0)
	{
		step_y = -1;
		side_dist_y = (game->player->y - (float)(map_y * TILE_SIZE)) * delta_y;
	}
	else
	{	
		step_y = 1;
		side_dist_y = ((float)(map_y + 1) * (float)TILE_SIZE - game->player->y) * delta_y;
	}
	while (game->map[map_y][map_x] != '1')
	{
		if (side_dist_x < side_dist_y)
		{
			distance = side_dist_x;
			side_dist_x += delta_x * TILE_SIZE;
			map_x += step_x;
		}
		else
		{
			distance = side_dist_y;
			side_dist_y += delta_y * TILE_SIZE;
			map_y += step_y;
		}
	}
	draw_single_line(game, dx, dy, distance);
}

void	draw_single_line(t_game *game, float dx, float dy, float distance)
{
	float	x;
	float	y;
	
	x = game->player->x;
	y = game->player->y;
	for (int i = 0; i < (int)distance; i++)
	{
		x += dx;
		y += dy;
		mlx_put_pixel(game->image, (int)x, (int)y, 0xFF0000FF);
	}
}
