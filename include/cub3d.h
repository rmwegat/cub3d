/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:18:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/06 19:45:14 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdbool.h>

# include "libft/libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/libft/get_next_line.h"

# include "MLX42/include/MLX42/MLX42.h"

# define MAX_MAP_ROWS 100
# define MAX_MAP_COLS 100
# define WIDTH 1024
# define HEIGHT 768
# define PI 3.14159265f
# define HALF_PI 1.57079637f
# define TWO_PI 6.28318530f
# define ONE_DEGREE 0.01745329f
# define TILE_SIZE 64
# define FOV 1.04719755f
# define ROT_SPEED 0.015f
# define MOV_SPEED 1.4f

typedef struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	angle;
}	t_player;

typedef struct s_textures
{
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
}	t_textures;

typedef struct s_config
{
	int	cc;
	int	fc;
	int	tc;
}	t_config;

typedef struct s_colors
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	u_int32_t	hex;
}	t_colors;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	t_player	*player;
	char		**map_copy;
	t_textures	textures;
	t_colors	celing_color;
	t_colors	floor_color;
	char		starting_direction;
}	t_game;

typedef struct s_ray
{
	float			distance;
	float			dx;
	float			dy;
	float			delta_x;
	float			delta_y;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				side;
	int				text_x;
	int				text_y;
	float			wall_x;
	float			wall_height;
	mlx_texture_t	*wall_texture;
}	t_ray;

// Parsing
int				is_valid_map_line(char *line);
void			extract_map(char *file, t_game *game);
int				check_input(char *argv, t_game *game);
int				parse_config(char *file, t_game *game);
int				parse_color(char *color_str, t_colors *color);
u_int32_t		get_hex(t_colors *rgba);
char			*skip_whitespace(char *str);

// Initialization
void			init(t_game *game);
char			**map_to_array(char *file);
char			**config_to_array(char *file);

// Memory
int				ft_alloc_game(t_game **game);
void			ft_free_map(char ***map);
void			ft_free_textures(t_textures *textures, bool terminate);
void			ft_free_game(t_game *game, bool terminate);
void			close_hook(void *param);

// Texture handling
int				check_wall_textures(t_game *game);
int				load_textures(t_game *game);
int				parse_we_ea_textures(char *line, \
				t_game *game, t_config *config);
int				parse_no_so_textures(char *line, \
				t_game *game, t_config *config);

// game
void			init_game(t_game *game);
void			draw_rays(t_game *game);
void			handle_keystrokes(mlx_key_data_t data, void *param);
void			update_keystrokes(void *param);
void			move_player(t_game *game, float dx, float dy, bool *redraw);
void			norm_angle(float *angle);
void			ray_caster(t_game *game, float angle, int i);
void			draw_v_strip(t_game *game, float distance, int i, t_ray *ray);
uint32_t		get_text_color(t_ray *ray, int j);
mlx_texture_t	*check_side(t_textures *texture, \
				float dx, float dy, int side);
void			get_dir_side_dist(t_ray *ray, float \
				*sx, float *sy, t_game *game);
void			dda_loop(t_game *game, t_ray *ray, \
				float *side_x, float *side_y);
void			handle_rotation(t_game *game, bool *redraw);

#endif