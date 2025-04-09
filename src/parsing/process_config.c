/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:45:26 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/09 14:14:51 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse_config(t_game *game, char **config_array)
{
	int i;

	i = 0;
	while (config_array[i])
	{
		if (ft_strncmp(config_array[i], "NO ", 3) == 0)
			game->textures.north = ft_strdup(config_array[i] + 3);
		else if (ft_strncmp(config_array[i], "SO ", 3) == 0)
			game->textures.south = ft_strdup(config_array[i] + 3);
		else if (ft_strncmp(config_array[i], "WE ", 3) == 0)
			game->textures.west = ft_strdup(config_array[i] + 3);
		else if (ft_strncmp(config_array[i], "EA ", 3) == 0)
			game->textures.east = ft_strdup(config_array[i] + 3);
		else if (ft_strncmp(config_array[i], "F ", 2) == 0)
			game->colors.floor = parse_color(config_array[i] + 2);
		else if (ft_strncmp(config_array[i], "C ", 2) == 0)
			game->colors.ceiling = parse_color(config_array[i] + 2);
		i++;
	}
}

