/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:55:53 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/03 17:12:07 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	load_textures(t_game *game)
{
	game->textures.north_texture= mlx_load_png(game->textures.north_path);
	game->textures.south_texture= mlx_load_png(game->textures.south_path);
	game->textures.east_texture= mlx_load_png(game->textures.east_path);
	game->textures.west_texture= mlx_load_png(game->textures.west_path);
	if (!game->textures.east_texture|| !game->textures.north_texture|| \
		!game->textures.south_texture|| !game->textures.west_texture)
	{
		ft_printf("Error: Failed to load one or more wall textures!\n");
		return (1);
	}
	return (0);
}