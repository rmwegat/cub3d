/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:14:31 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/06 19:46:07 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	parse_colors(char *line, t_game *game, t_config *config)
{
	if (!ft_strncmp(line, "F", 1) && ++(config->fc))
		parse_color(skip_whitespace(line + 1), &game->floor_color);
	else if (!ft_strncmp(line, "C", 1) && ++(config->cc))
		parse_color(skip_whitespace(line + 1), &game->celing_color);
	return (0);
}

int	parse_config_line(char *line, t_game *game, t_config *config, int fd)
{
	if (ft_strlen(line) == 0)
		free(line);
	else
	{
		if (parse_no_so_textures(line, game, config) \
		|| parse_we_ea_textures(line, game, config) \
		|| parse_colors(line, game, config))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
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
	line = get_next_line(fd);
	while (line)
	{
		if (parse_config_line(line, game, &config, fd))
			return (1);
		line = get_next_line(fd);
	}
	close(fd);
	if (config.fc != 1 || config.cc != 1 || config.tc != 4)
		return (perror("Error: Missing or invalid configuration!\n"), 1);
	return (extract_map(file, game), 0);
}
