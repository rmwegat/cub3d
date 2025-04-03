/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:18:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/03 12:51:17 by rwegat           ###   ########.fr       */
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
# include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 1280
#define HEIGHT 720


typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		**map;

}	t_game;

// Parsing
int check_input(int argc, char *argv);


#endif