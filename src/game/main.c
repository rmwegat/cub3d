/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:12:46 by temil-da          #+#    #+#             */
/*   Updated: 2025/04/30 19:07:19 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(void)
{
	t_game game;
	t_player player;
	game.player = &player;
	init_player(&player);
	game.map = init_map();
	init_game(&game);
	draw_map(&game);
	draw_player(&game);
	draw_rays(&game);
	mlx_loop_hook(game.mlx, &update_keystrokes, &game);
	mlx_loop(game.mlx);
	return (0);
}