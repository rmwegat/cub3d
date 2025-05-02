/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:18:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/30 19:48:54 by rwegat           ###   ########.fr       */
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

# include "libft/libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/libft/get_next_line.h"

# include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 1024
#define HEIGHT 768
#define PI 3.14159265f
#define HALF_PI PI/2
#define TWO_PI 6.28318530f
#define ONE_DEGREE 0.01745329f
#define	TILE_SIZE 64
#define	FOV	60
#define	ROT_SPEED 0.005f
#define MOV_SPEED 0.4f
#define DEBUG_MODE 1

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	mlx_image_t		*north_img;
	mlx_texture_t	*north_text;
	mlx_image_t		*south_img;
	mlx_texture_t	*south_text;
	mlx_image_t		*west_img;
	mlx_texture_t	*west_text;
	mlx_image_t		*east_img;
	mlx_texture_t	*east_text;
}	t_textures;

typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_colors;

typedef struct s_player
{
	float	x;
	float	y;
	float		dx;
	float		dy;
	float		angle;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	char		**map_copy;
	t_textures	textures;
	t_colors	celing_color;
	t_colors	floor_color;
	t_player	player;
	char		starting_direction;
	bool		keys[348];
}	t_game;


// Parsing
void	extract_map(char *file, t_game *game);
int		check_input(char *argv, t_game *game);
int		parse_config(char *file, t_game *game);
int		parse_color(char *color_str, t_colors *color);

// initialisation
void	init(t_game *game);
char	**map_to_array(char *file);
char	**config_to_array(char *file);

// memory
int		ft_alloc_game(t_game **game);
int		ft_alloc_map(char ***map);
void	ft_free_map(char **map);
void	ft_free_textures(t_textures *textures);
void	ft_free_game(t_game *game);

// Texture handling
int		ft_open_image(t_game *game, mlx_image_t **img_direction,
		char *img_path);
int		ft_open_image_keep_text(t_game *game, mlx_image_t **img_direction,
		mlx_texture_t **text, char *img_path);
int		check_wall_textures(t_game *game);

#endif