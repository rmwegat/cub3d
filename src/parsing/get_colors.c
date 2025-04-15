/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:22:36 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/15 15:22:42 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_count_comma(char *str)
{
	int	i;
	int	count_comma;

	i = 0;
	count_comma = 0;
	while (str[i])
	{
		if (str[i++] == ',')
			count_comma++;
	}
	return (count_comma);
}

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
	char	*r;
	char	*g;
	char	*b;
	char	**split;

	if (ft_strlen(color_str) == 0 || ft_count_comma(color_str) != 2)
		return (ft_error("Error: Invalid color format!"));
	split = ft_split(color_str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (ft_free_split(split), ft_printf("Error: RGB 0-255!"));
	r = ft_strdup(split[0]);
	g = ft_strdup(split[1]);
	b = ft_strdup(split[2]);
	ft_free_split(split);
	if (!r || !g || !b)
		return (free(r), free(g), free(b), ft_printf("Error: allocation failed!"));
	color->r = ft_atoi(r);
	color->g = ft_atoi(g);
	color->b = ft_atoi(b);
	color->a = 255;
	if (color->r > 255 || color->g > 255 || color->b > 255 || color->r < 0
		|| color->g < 0 || color->b < 0)
		return (free(r), free(g), free(b), ft_printf("Error: RGB 0-255!"));
	return (free(r), free(g), free(b), 0);
}
