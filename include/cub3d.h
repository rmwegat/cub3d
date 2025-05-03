/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:18:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/03 20:56:01 by temil-da         ###   ########.fr       */
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

# define WIDTH 1024
# define HEIGHT 768
# define PI 3.14159265f
# define HALF_PI (PI / 2)
# define TWO_PI 6.28318530f
# define ONE_DEGREE 0.01745329f
# define TILE_SIZE 64
# define FOV (HALF_PI / 3)
# define ROT_SPEED 0.01f
# define MOV_SPEED 0.9f

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

typedef struct s_colors
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
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

typedef	struct s_ray
{
	float			distance;
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
void		extract_map(char *file, t_game *game);
int			check_input(char *argv, t_game *game);
int			parse_config(char *file, t_game *game);
int			parse_color(char *color_str, t_colors *color);
u_int32_t	get_hex(t_colors *rgba);

// Initialization
void	init(t_game *game);
char	**map_to_array(char *file);
char	**config_to_array(char *file);

// Memory
int		ft_alloc_game(t_game **game);
int		ft_alloc_map(char ***map);
void	ft_free_map(char **map);
void	ft_free_textures(t_textures *textures);
void	ft_free_game(t_game *game);

// Texture handling
int		check_wall_textures(t_game *game);
int		load_textures(t_game *game);



// game
void			init_game(t_game *game);
void			draw_rays(t_game *game);
void			handle_keystrokes(mlx_key_data_t data, void *param);
void			update_keystrokes(void *param);
void			move_player(t_game *game, float dx, float dy, bool *redraw);
void			norm_angle(float *angle);
void			ray_caster(t_game *game, float angle, int i);
void			draw_single_line(t_game *game, float dx, float dy, float distance);
void			draw_v_strip(t_game *game, float distance, int i, t_ray *ray);
uint32_t		get_text_color(mlx_texture_t *texture, t_ray *ray, int j);
mlx_texture_t	*check_side(t_textures *texture, float dx, float dy, int side);

#endif
