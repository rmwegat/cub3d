/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:55:53 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/30 20:04:10 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_wall_textures(t_game *game)
{
	(void)game;
	// if (ft_open_image_keep_text(game, &game->textures.north_img, \
	// 		&game->textures.north_text, game->textures.north)
	// 	* ft_open_image_keep_text(game, &game->textures.south_img, \
	// 		&game->textures.south_text, game->textures.south)
	// 	* ft_open_image_keep_text(game, &game->textures.west_img, \
	// 		&game->textures.west_text, game->textures.west)
	// 	* ft_open_image_keep_text(game, &game->textures.east_img, \
	// 		&game->textures.east_text, game->textures.east) == 0)
	// {
	// 	ft_printf("Error: Failed to load one or more wall textures!\n");
	// 	return (1);
	// }
	return (0);
}


int	ft_open_image(t_game *game, mlx_image_t **img_direction, char *img_path)
{
	mlx_texture_t	*text;

	text = mlx_load_png(img_path);
	if (!text)
		return (1);
	*img_direction = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	return (0);
}

int	ft_open_image_keep_text(t_game *game, mlx_image_t **img_direction,
		mlx_texture_t **text, char *img_path)
{
	*text = mlx_load_png(img_path);
	if (!*text)
		return (0);
	*img_direction = mlx_texture_to_image(game->mlx, *text);
	return (1);
}
