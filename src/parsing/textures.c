/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:55:53 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/06 19:45:20 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid_map_line(char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	if (line[j] != '1')
		return (0);
	while (line[j])
	{
		if (line[j] != '1' && line[j] != '0' && \
		line[j] != 'N' && line[j] != 'S' && \
		line[j] != 'E' && line[j] != 'W' && \
		line[j] != ' ' && line[j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	parse_no_so_textures(char *line, t_game *game, t_config *config)
{
	char	*trimmed;
	char	*new_path;

	if (ft_strlen(line) < 3)
		return (0);
	trimmed = skip_whitespace(line + 2);
	if (!trimmed || *trimmed == '\0')
		return (perror("Error: Invalid texture path!"), 1);
	if (!ft_strncmp(line, "NO", 2) && ++(config->tc))
	{
		new_path = ft_strtrim(trimmed, "\n");
		if (!new_path)
			return (perror("Error: Memory allocation failed!"), 1);
		free(game->textures.north_path);
		game->textures.north_path = new_path;
	}
	else if (!ft_strncmp(line, "SO", 2) && ++(config->tc))
	{
		new_path = ft_strtrim(trimmed, "\n");
		if (!new_path)
			return (perror("Error: Memory allocation failed!"), 1);
		free(game->textures.south_path);
		game->textures.south_path = new_path;
	}
	return (0);
}

int	parse_we_ea_textures(char *line, t_game *game, t_config *config)
{
	char	*trimmed;
	char	*new_path;

	if (ft_strlen(line) < 3)
		return (0);
	trimmed = skip_whitespace(line + 2);
	if (!trimmed || *trimmed == '\0')
		return (perror("Error: Invalid texture path!"), 1);
	if (!ft_strncmp(line, "WE", 2) && ++(config->tc))
	{
		new_path = ft_strtrim(trimmed, "\n");
		if (!new_path)
			return (perror("Error: Memory allocation failed!"), 1);
		free(game->textures.west_path);
		game->textures.west_path = new_path;
	}
	else if (!ft_strncmp(line, "EA", 2) && ++(config->tc))
	{
		new_path = ft_strtrim(trimmed, "\n");
		if (!new_path)
			return (perror("Error: Memory allocation failed!"), 1);
		free(game->textures.east_path);
		game->textures.east_path = new_path;
	}
	return (0);
}

int	load_textures(t_game *game)
{
	game->textures.north_texture = mlx_load_png(game->textures.north_path);
	game->textures.south_texture = mlx_load_png(game->textures.south_path);
	game->textures.east_texture = mlx_load_png(game->textures.east_path);
	game->textures.west_texture = mlx_load_png(game->textures.west_path);
	if (!game->textures.east_texture || !game->textures.north_texture || \
!game->textures.south_texture || !game->textures.west_texture)
	{
		perror("Error: Failed to load one or more wall textures!\n");
		return (1);
	}
	return (0);
}
