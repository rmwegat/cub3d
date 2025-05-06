/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:14:31 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/06 11:22:11 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}
int	parse_textures_and_colors(char *line, t_game *game, \
	int *floors, int *celings, int *texture_paths)
{
	char	*trimmed;

	trimmed = skip_whitespace(line + 2);
	if (!ft_strncmp(line, "NO", 2) && ++(*texture_paths))
		game->textures.north_path = ft_strtrim(trimmed, "\n");
	else if (!ft_strncmp(line, "SO", 2) && ++(*texture_paths))
		game->textures.south_path = ft_strtrim(trimmed, "\n");
	else if (!ft_strncmp(line, "WE", 2) && ++(*texture_paths))
		game->textures.west_path = ft_strtrim(trimmed, "\n");
	else if (!ft_strncmp(line, "EA", 2) && ++(*texture_paths))
		game->textures.east_path = ft_strtrim(trimmed, "\n");
	else if (!ft_strncmp(line, "F", 1) && ++(*floors))
		parse_color(skip_whitespace(line + 1), &game->floor_color);
	else if (!ft_strncmp(line, "C", 1) && ++(*celings))
		parse_color(skip_whitespace(line + 1), &game->celing_color);
	return (0);
}

int	parse_config(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		fc;
	int		cc;
	int		tc;

	cc = 0;
	fc = 0;
	tc = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error: Failed to open config file!"), 1);
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) == 0)
			free(line);
		else
			parse_textures_and_colors(line, game, &fc, &cc, &tc);
		free(line);
	}
	close(fd);
	if (fc != 1 || cc != 1 || tc != 4)
		return (perror("Error: Missing or invalid configuration!\n"), 1);
	return (extract_map(file, game), 0);
}
