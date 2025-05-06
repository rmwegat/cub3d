/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:14:31 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/06 13:39:36 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	parse_textures_and_colors(char *line, t_game *game, t_config *config)
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
			return (perror("Error: Memory allocation failed for north_path!"), 1);
		free(game->textures.north_path);
		game->textures.north_path = new_path;
	}
	else if (!ft_strncmp(line, "SO", 2) && ++(config->tc))
	{
		new_path = ft_strtrim(trimmed, "\n");
		if (!new_path)
			return (perror("Error: Memory allocation failed for south_path!"), 1);
		free(game->textures.south_path);
		game->textures.south_path = new_path;
	}
	else if (!ft_strncmp(line, "WE", 2) && ++(config->tc))
	{
		new_path = ft_strtrim(trimmed, "\n");
		if (!new_path)
			return (perror("Error: Memory allocation failed for west_path!"), 1);
		free(game->textures.west_path);
		game->textures.west_path = new_path;
	}
	else if (!ft_strncmp(line, "EA", 2) && ++(config->tc))
	{
		new_path = ft_strtrim(trimmed, "\n");
		if (!new_path)
			return (perror("Error: Memory allocation failed for east_path!"), 1);
		free(game->textures.east_path);
		game->textures.east_path = new_path;
	}
	else if (!ft_strncmp(line, "F", 1) && ++(config->fc))
		parse_color(skip_whitespace(line + 1), &game->floor_color);
	else if (!ft_strncmp(line, "C", 1) && ++(config->cc))
		parse_color(skip_whitespace(line + 1), &game->celing_color);
	return (0);
}

int	parse_config(char *file, t_game *game)
{
	int			fd;
	char		*line;
	t_config	config;

	config.cc = 0;
	config.fc = 0;
	config.tc = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error: Failed to open config file!"), 1);
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) == 0)
			free(line);
		else
			parse_textures_and_colors(line, game, &config);
		free(line);
	}
	close(fd);
	if (config.fc != 1 || config.cc != 1 || config.tc != 4)
		return (perror("Error: Missing or invalid configuration!\n"), 1);
	return (extract_map(file, game), 0);
}
