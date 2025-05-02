/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:55:53 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/02 16:43:01 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	load_textures(t_game *game)
{
	printf("%s\n%s\n%s\n%s\n", game->textures.east, game->textures.north, game->textures.south, game->textures.west);
	game->textures.north_text = mlx_load_png(game->textures.north);
	game->textures.south_text = mlx_load_png(game->textures.south);
	game->textures.east_text = mlx_load_png(game->textures.east);
	game->textures.west_text = mlx_load_png(game->textures.west);
	if (!game->textures.east_text || !game->textures.north_text || !game->textures.south_text || !game->textures.west_text)
	{
		ft_printf("Error: Failed to load one or more wall textures!\n");
		return (1);
	}
	return (0);
}