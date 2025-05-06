/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:50 by temil-da          #+#    #+#             */
/*   Updated: 2025/05/05 20:54:12 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	get_text_color(t_ray *ray, int j)
{
	t_colors		color;
	mlx_texture_t	*t;
	float			w;

	t = ray->wall_texture;
	w = ray->wall_height;
	ray->text_x = (int)(ray->wall_x * t->width);
	if (ray->text_x < 0)
		ray->text_x = 0;
	if (ray->text_x >= (int)t->width)
		ray->text_x = t->width - 1;
	ray->text_y = (int)(((float)(j - (HEIGHT / 2 - w / 2)) / w) * t->height);
	if (ray->text_y < 0)
		ray->text_y = 0;
	if (ray->text_y >= (int)t->height)
		ray->text_y = t->height - 1;
	color.r = t->pixels[(ray->text_y * t->width + ray->text_x) * 4 + 0];
	color.g = t->pixels[(ray->text_y * t->width + ray->text_x) * 4 + 1];
	color.b = t->pixels[(ray->text_y * t->width + ray->text_x) * 4 + 2];
	color.a = t->pixels[(ray->text_y * t->width + ray->text_x) * 4 + 3];
	return (get_hex(&color));
}

void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	ft_free_game(game, true);
}
