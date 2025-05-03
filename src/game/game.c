/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:09 by temil-da          #+#    #+#             */
/*   Updated: 2025/05/03 21:02:26 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->image, 0, 0);
	if (load_textures(game)) // TODO ERROR HANDLE
		exit(1);
}

void    update_keystrokes(void *param)
{
	t_game	*game;
	bool	redraw;
	
	game = (t_game *) param;
	redraw = false;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, game->player->dx * MOV_SPEED, game->player->dy * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, game->player->dy * MOV_SPEED, -game->player->dx * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, -game->player->dx * MOV_SPEED, -game->player->dy * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, -game->player->dy * MOV_SPEED, game->player->dx * MOV_SPEED, &redraw);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
			game->player->angle -= ROT_SPEED;
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
			game->player->angle += ROT_SPEED;
		norm_angle(&game->player->angle);
		game->player->dx = cos(game->player->angle);
		game->player->dy = sin(game->player->angle);
		redraw = true;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		exit (0);
	if (redraw)
		draw_rays(game);
}

void	move_player(t_game *game, float dx, float dy, bool *redraw)
{
	game->player->x += dx;
	game->player->y += dy;
	if (game->map[(int)(game->player->y / TILE_SIZE)][(int)(game->player->x / TILE_SIZE)] == '1')
	{
		game->player->x -= dx;
		game->player->y -= dy;
		return ;
	}
	*redraw = true;
}	


void	norm_angle(float *angle)
{
	if (*angle < 0)
	*angle += TWO_PI;
	else if (*angle > TWO_PI)
	*angle -= TWO_PI;
}

void	draw_rays(t_game *game)
{
	float	start;
	float	ray_angle;
	float	ray_step;

	start = game->player->angle - (FOV / 2);
	ray_step = FOV / WIDTH;
	for (int i = 0; i < WIDTH; i++)
	{
		ray_angle = start + i * ray_step;
		ray_caster(game, ray_angle, i);
	}
}

void	ray_caster(t_game *game, float angle, int i)
{
	t_ray	ray;
	float	dx;
	float	dy;
	float	delta_x;
	float	delta_y;
	int		step_x;		//STEPX, STEPY, THE DIRECTION WE ARE STEPPING ON THE X/Y AXIS (POSITIVE OR NEGATIVE)
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	float	hit_point;

	dx = cos(angle);
	dy = sin(angle);
	ray.map_x = (int)(game->player->x / TILE_SIZE);
	ray.map_y = (int)(game->player->y / TILE_SIZE);
	delta_x = sqrt(1 + (dy / dx) * (dy / dx)); // THIS CALCULATION TELLS US THE DISTANCE WE NEED TO TRAVEL IN OUR RAY DIRECTION TO TRAVEL ONE UNIT OF X OR Y
	delta_y = sqrt(1 + (dx / dy) * (dx / dy));
	if (dx < 0)
	{
		step_x = -1;
		side_dist_x = (game->player->x - (float)(ray.map_x * TILE_SIZE)) * delta_x; // IN THIS STEP WE ARE SETTING OUR STEP_X AND STEP_Y TO A NEGATIVE OR POSITIVE 1 DEPENDING ON THE DIRECTION AND WE FIND OUT THE DISTANCE OF THE RAY FOR THE CURRENT STARTING CELL
	}																				// SO THAT WE CAN START THE ALGORIGHM LOOP
	else
	{
		step_x = 1;
		side_dist_x = ((float)(ray.map_x + 1) * (float)TILE_SIZE - game->player->x) * delta_x;
	}
	if (dy < 0)
	{
		step_y = -1;
		side_dist_y = (game->player->y - (float)(ray.map_y * TILE_SIZE)) * delta_y;
	}
	else
	{	
		step_y = 1;
		side_dist_y = ((float)(ray.map_y + 1) * (float)TILE_SIZE - game->player->y) * delta_y;
	}
	while (game->map[ray.map_y][ray.map_x] != '1')
	{
		if (side_dist_x < side_dist_y)
		{
			ray.distance = side_dist_x;
			side_dist_x += delta_x * TILE_SIZE;
			ray.map_x += step_x;
			ray.side = 0;
		}
		else
		{
			ray.distance = side_dist_y;
			side_dist_y += delta_y * TILE_SIZE;
			ray.map_y += step_y;
			ray.side = 1;
		}
	}
	ray.wall_texture = check_side(&game->textures, dx, dy, ray.side);
	if (ray.side == 0)
		hit_point = game->player->y + ray.distance * sin(angle);
	else
		hit_point = game->player->x + ray.distance * cos(angle);
	ray.wall_x = fmod(hit_point, TILE_SIZE) / TILE_SIZE;
	draw_v_strip(game, ray.distance * cos(angle - game->player->angle), i, &ray); // DISTANCE WITH THE FORMULA APPLIED TO NORMALIZE THE FISH EYE EFFECT
}

void	draw_v_strip(t_game *game, float distance ,int i, t_ray *ray)
{
	float			p_height;
	float			d;
	float			w_start;
	float			w_end;	
	
	p_height = TILE_SIZE/2; // PLAYER HEIGHT, NORMALLY HALF THE SCREEN
	d = (WIDTH / 2) / tan(FOV/2); // ONE OF THE MOST IMPORTANT FORMULAS IN RAY CASTING, IT IS THE BASE OF DECIDING HOW TALL SHOULD A WALL SLICE BE DEPENDING ON THE RAY DISTANCE
	w_start = HEIGHT/2 - ((d * p_height) / distance); // FORMULA FOR CEILING PIXELS
	w_end = HEIGHT/2 + ((d * p_height) / distance); // FORMULA FOR WALL PIXELS
	ray->wall_height = w_end - w_start;
	for (int j = 0; j < HEIGHT; ++j)
	{
		if (j < w_start)
			mlx_put_pixel(game->image, i, j, game->celing_color.hex);
		else if (j <= w_end)
			mlx_put_pixel(game->image, i, j, get_text_color(ray->wall_texture, ray, j));
		else
			mlx_put_pixel(game->image, i, j, game->floor_color.hex); // FLOOR
	}
}

uint32_t	get_text_color(mlx_texture_t *texture, t_ray *ray, int j)
{
	t_colors	color;
	
	if (!texture || ray->wall_height <= 0)			//Whatever maybe this check is not needed.... I dont know if wither of those two counditions would be possibe to be wrong so far deep in the program, if yes, I have to send the full game struct here later for cleanup
		exit(1);
	ray->text_x = (int)(ray->wall_x * texture->width);
	if (ray->text_x < 0)
		ray->text_x = 0;
	if (ray->text_x >= (int)texture->width)
		ray->text_x = texture->width - 1;
	ray->text_y = (int)(((float)(j - (HEIGHT / 2  - ray->wall_height / 2)) / ray->wall_height) * texture->height);
	if (ray->text_y < 0)
		ray->text_y = 0;
	if (ray->text_y >= (int)texture->height)
		ray->text_y = texture->height - 1;
	color.r = texture->pixels[(ray->text_y * texture->width + ray->text_x) * 4 + 0];
	color.g = texture->pixels[(ray->text_y * texture->width + ray->text_x) * 4 + 1];
	color.b = texture->pixels[(ray->text_y * texture->width + ray->text_x) * 4 + 2];
	color.a = texture->pixels[(ray->text_y * texture->width + ray->text_x) * 4 + 3];
	return (get_hex(&color));
}

mlx_texture_t	*check_side(t_textures *texture, float dx, float dy, int side)
{
	if (side == 0)
	{
		if (dx > 0)
			return(texture->east_texture);
		else
			return(texture->west_texture);
	}
	else
	{
		if (dy > 0)
			return(texture->south_texture);
		else
			return(texture->north_texture);
	}
}