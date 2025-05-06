/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:22:36 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/06 11:59:43 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

u_int32_t	get_hex(t_colors *rgba)
{
	return ((u_int32_t)rgba->r << 24 | \
	(u_int32_t)rgba->g << 16 | (u_int32_t)rgba->b << 8 | 255);
}

int	atounit8(const char *str, uint8_t *result)
{
	int	value;

	value = ft_atoi(str);
	if (value < 0 || value > 255)
		return (perror("Error: Invalid color value!"), 1);
	*result = (uint8_t)value;
	return (0);
}

int	parse_color(char *color_str, t_colors *color)
{
	char	**split;

	split = ft_split(color_str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (ft_free_map(&split), perror("Error: Invalid RGB format!"), 1);
	if (atounit8(split[0], &color->r) || atounit8(split[1], &color->g) \
	|| atounit8(split[2], &color->b))
		return (ft_free_map(&split), 1);
	color->a = 255;
	ft_free_map(&split);
	color->hex = get_hex(color);
	return (0);
}
