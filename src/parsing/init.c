/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:59:17 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/08 16:00:16 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid_color(char *argv)
{
	(void)argv;
	return (0);
}

int	is_valid_texture(char *argv)
{
	(void)argv;
	return (0);
}

int	is_valid_map(char **map)
{
	(void)map;
	return (0);
}

int	check_config(char *argv, t_game *game)
{
	game->map = map_to_array(argv);
	if (is_valid_map(game->map))
		return (ft_printf("Error: Invalid map configuration.\n"));
	if (is_valid_texture(argv))
		return (ft_printf("Error: Invalid texture configuration.\n"));
	if (is_valid_color(argv))
		return (ft_printf("Error: Invalid color configuration.\n"));
	return (0);
}

int	check_input(char *argv, t_game *game)
{
	int	fd;

	if (!argv || ft_strlen(argv) < 5 || \
	ft_strncmp(argv + ft_strlen(argv) - 4, ".cub", 4) != 0)
		return (ft_printf("Error: Invalid file extension. Expected '.cub'.\n"));
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: File does not exist.\n"));
	close(fd);
	if (check_config(argv, game))
		return (ft_printf("Error: Invalid configuration in the .cub file.\n"));
	return (0);
}
