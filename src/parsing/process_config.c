/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:14:31 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/15 15:22:26 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

void	get_textures(t_game *game, char **config_array)
{
	int i;

	i = 0;
	while (config_array[i])
	{
		if (ft_strncmp(config_array[i], "NO", 2) == 0)
			game->textures.north = ft_strdup(skip_whitespace(config_array[i] + 2));
		else if (ft_strncmp(config_array[i], "SO", 2) == 0)
			game->textures.south = ft_strdup(skip_whitespace(config_array[i] + 2));
		else if (ft_strncmp(config_array[i], "WE", 2) == 0)
			game->textures.west = ft_strdup(skip_whitespace(config_array[i] + 2));
		else if (ft_strncmp(config_array[i], "EA", 2) == 0)
			game->textures.east = ft_strdup(skip_whitespace(config_array[i] + 2));
		else if (ft_strncmp(config_array[i], "F", 1) == 0)
			parse_color(skip_whitespace(config_array[i] + 1), &game->floor_color);
		else if (ft_strncmp(config_array[i], "C", 1) == 0)
			parse_color(skip_whitespace(config_array[i] + 1), &game->celing_color);
		i++;
	}
}

