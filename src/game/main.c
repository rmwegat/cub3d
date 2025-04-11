/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:12:46 by temil-da          #+#    #+#             */
/*   Updated: 2025/04/11 17:00:31 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(void)
{
	t_game game;
	game.player_x = 7 * TILE_SIZE + TILE_SIZE / 2;
	game.player_y = 2 * TILE_SIZE + TILE_SIZE / 2;
	game.player_angle = PI / 2;
	game.map = init_map();
	init_game(&game);
	draw_map(&game);
	draw_player(&game);
	mlx_loop(game.mlx);
	return (0);
}