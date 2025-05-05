/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:50:50 by temil-da          #+#    #+#             */
/*   Updated: 2025/05/05 20:57:39 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray_caster(t_game *game, float angle, int i)
{
	t_ray	ray;
	float	side_dist_x;
	float	side_dist_y;
	float	hit_point;

	ray.side = 0;
	ray.distance = 0;
	ray.dx = cos(angle);
	ray.dy = sin(angle);
	ray.map_x = (int)(game->player->x / TILE_SIZE);
	ray.map_y = (int)(game->player->y / TILE_SIZE);
	ray.delta_x = sqrt(1 + (ray.dy / ray.dx) * (ray.dy / ray.dx));
	ray.delta_y = sqrt(1 + (ray.dx / ray.dy) * (ray.dx / ray.dy));
	get_dir_side_dist(&ray, &side_dist_x, &side_dist_y, game);
	dda_loop(game, &ray, &side_dist_x, &side_dist_y);
	ray.wall_texture = check_side(&game->textures, ray.dx, ray.dy, ray.side);
	if (ray.side == 0)
		hit_point = game->player->y + ray.distance * sin(angle);
	else
		hit_point = game->player->x + ray.distance * cos(angle);
	ray.wall_x = fmod(hit_point, TILE_SIZE) / TILE_SIZE;
	ray.distance *= cos(angle - game->player->angle);
	draw_v_strip(game, ray.distance, i, &ray);
}

void	get_dir_side_dist(t_ray *ray, float *sx, float *sy, t_game *game)
{
	float	dlt_x;
	float	dlt_y;

	dlt_x = ray->delta_x;
	dlt_y = ray->delta_y;
	if (ray->dx < 0)
	{
		ray->step_x = -1;
		*sx = (game->player->x - (float)(ray->map_x * TILE_SIZE)) * dlt_x;
	}
	else
	{
		ray->step_x = 1;
		*sx = ((ray->map_x + 1) * (float)TILE_SIZE - game->player->x) * dlt_x;
	}
	if (ray->dy < 0)
	{
		ray->step_y = -1;
		*sy = (game->player->y - (float)(ray->map_y * TILE_SIZE)) * dlt_y;
	}
	else
	{
		ray->step_y = 1;
		*sy = ((ray->map_y + 1) * (float)TILE_SIZE - game->player->y) * dlt_y;
	}
}

void	dda_loop(t_game *game, t_ray *ray, float *side_x, float *side_y)
{
	while (game->map[ray->map_y][ray->map_x] != '1')
	{
		if (*side_x < *side_y)
		{
			ray->distance = *side_x;
			*side_x += ray->delta_x * TILE_SIZE;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->distance = *side_y;
			*side_y += ray->delta_y * TILE_SIZE;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}

mlx_texture_t	*check_side(t_textures *texture, float dx, float dy, int side)
{
	if (side == 0)
	{
		if (dx > 0)
			return (texture->east_texture);
		else
			return (texture->west_texture);
	}
	else
	{
		if (dy > 0)
			return (texture->south_texture);
		else
			return (texture->north_texture);
	}
}

void	draw_v_strip(t_game *game, float distance, int i, t_ray *ray)
{
	float	d;
	float	w_start;
	float	w_end;
	int		j;

	d = (WIDTH / 2) / tan(FOV / 2);
	w_start = HEIGHT / 2 - ((d * (TILE_SIZE / 2)) / distance);
	w_end = HEIGHT / 2 + ((d * (TILE_SIZE / 2)) / distance);
	j = 0;
	ray->wall_height = w_end - w_start;
	while (++j < HEIGHT)
	{
		if (j < w_start)
			mlx_put_pixel(game->image, i, j, game->celing_color.hex);
		else if (j <= w_end)
			mlx_put_pixel(game->image, i, j, get_text_color(ray, j));
		else
			mlx_put_pixel(game->image, i, j, game->floor_color.hex);
	}
}
