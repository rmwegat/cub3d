/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:14:07 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/03 12:35:44 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	main(int argc, char	**argv)
{
	t_game	game;
	
	if (argc != 2)
		return (EXIT_FAILURE);
	if (check_input(argc, argv[1]))
		return (EXIT_FAILURE);
	init_game(&game);
	if (parse(&game, argv))
		return (EXIT_FAILURE);
	init_mlx(&game);
	
	// mlx_loop_hook(game.mlx, &game.image, &game.image);
	// mlx_loop(game.mlx);

	return (0);
}