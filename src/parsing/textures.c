/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:55:53 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/02 17:05:58 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	load_textures(t_game *game)
{
	game->textures.north_text = mlx_load_png("textures/bluestone.png");
	game->textures.south_text = mlx_load_png("textures/bluestone.png");
	game->textures.east_text = mlx_load_png("textures/bluestone.png");
	game->textures.west_text = mlx_load_png("textures/bluestone.png");
	if (!game->textures.east_text || !game->textures.north_text || !game->textures.south_text || !game->textures.west_text)
	{
		ft_printf("Error: Failed to load one or more wall textures!\n");
		return (1);
	}
	return (0);
}