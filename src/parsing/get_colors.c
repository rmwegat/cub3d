/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:22:36 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/17 15:39:48 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parse_color(char *color_str, t_colors *color)
{
	char	**split;

	split = ft_split(color_str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (ft_free_split(split), perror("Error: Invalid RGB format!"), 1);
	color->r = ft_atoi(split[0]);
	color->g = ft_atoi(split[1]);
	color->b = ft_atoi(split[2]);
	color->a = 255;
	ft_free_split(split);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
		return (perror("Error: RGB 0-255!"), 1);
	return (0);
}
