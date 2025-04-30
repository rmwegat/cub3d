/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:18:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/30 19:04:11 by temil-da         ###   ########.fr       */
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
#define	FOV	HALF_PI / 3
#define	ROT_SPEED 0.005f
#define MOV_SPEED 0.4f
#define DEBUG_MODE 1


typedef	struct s_player
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	float		angle;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	t_player	*player;
}	t_game;

// Parsing
int check_input(char *argv, t_game *game);

// initialisation
char **map_to_array(char *argv);

#endif