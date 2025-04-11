/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:18:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/08 16:47:22 by temil-da         ###   ########.fr       */
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
#define	TILE_SIZE 64

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;
	float		player_x;
	float		player_y;
	float		player_angle;
}	t_game;

// Parsing
int check_input(char *argv, t_game *game);

// initialisation
char **map_to_array(char *argv);

#endif