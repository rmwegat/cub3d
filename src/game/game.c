/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:09 by temil-da          #+#    #+#             */
/*   Updated: 2025/05/06 13:34:02 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
	if (!load_textures(game))
		return ;
	ft_free_game(game);
	exit(1);
}

void	draw_rays(t_game *game)
{
	float	start;
	float	ray_angle;
	float	ray_step;
	int		i;

	i = 0;
	start = game->player->angle - (FOV / 2);
	ray_step = FOV / WIDTH;
	while (i < WIDTH)
	{
		ray_angle = start + i * ray_step;
		ray_caster(game, ray_angle, i);
		i++;
	}
}
