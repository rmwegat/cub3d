/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:18:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/17 14:47:23 by rwegat           ###   ########.fr       */
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

#define WIDTH 1280
#define HEIGHT 720

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
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
	float	direction;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	t_textures	textures;
	t_colors	celing_color;
	t_colors	floor_color;
	t_player	player;
}	t_game;


// Parsing
int		parse_config(char *file, t_game *game);
int		check_input(char *argv, t_game *game);
int		parse_color(char *color_str, t_colors *color);
void	ft_free_split(char **split);
void	extract_map(char *file, t_game *game);

// initialisation
char	**config_to_array(char *file);
char	**map_to_array(char *file);

#endif