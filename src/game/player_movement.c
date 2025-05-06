/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:46:15 by temil-da          #+#    #+#             */
/*   Updated: 2025/05/06 01:47:13 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	update_keystrokes(void *param)
{
	t_game	*game;
	bool	redraw;
	float	dx;
	float	dy;

	game = (t_game *) param;
	redraw = false;
	dx = game->player->dx;
	dy = game->player->dy;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, dx * MOV_SPEED, dy * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, dy * MOV_SPEED, -dx * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, -dx * MOV_SPEED, -dy * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, -dy * MOV_SPEED, dx * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || \
mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		handle_rotation(game, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		ft_free_game(game, true);
	if (redraw)
		draw_rays(game);
}

void	move_player(t_game *game, float dx, float dy, bool *redraw)
{
	int	map_x;
	int	map_y;

	game->player->x += dx;
	game->player->y += dy;
	map_x = (int)(game->player->x / TILE_SIZE);
	map_y = (int)(game->player->y / TILE_SIZE);
	if (game->map[map_y][map_x] == '1')
	{
		game->player->x -= dx;
		game->player->y -= dy;
		return ;
	}
	*redraw = true;
}

void	norm_angle(float *angle)
{
	if (*angle < 0)
		*angle += TWO_PI;
	else if (*angle > TWO_PI)
		*angle -= TWO_PI;
}

void	handle_rotation(t_game *game, bool *redraw)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->player->angle -= ROT_SPEED;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->player->angle += ROT_SPEED;
	norm_angle(&game->player->angle);
	game->player->dx = cos(game->player->angle);
	game->player->dy = sin(game->player->angle);
	*redraw = true;
}
