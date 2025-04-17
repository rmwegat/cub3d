/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:12:46 by temil-da          #+#    #+#             */
/*   Updated: 2025/04/12 19:50:50 by temil-da         ###   ########.fr       */
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
	draw_direction_line(&game);
	mlx_key_hook(game.mlx, &handle_keystrokes, &game);
	mlx_loop_hook(game.mlx, &update_keystrokes, &game);
	mlx_loop(game.mlx);
	return (0);
}