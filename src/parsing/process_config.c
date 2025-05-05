/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:14:31 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/05 15:48:23 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	parse_config(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error: Failed to open config file!"), 1);
	if (ft_alloc_map(&game->map))
		return (close(fd), 1);
	while ((line = get_next_line(fd)))
	{
		if (ft_strlen(line) == 0)
			free(line);
		if (ft_strncmp(line, "NO", 2) == 0)
			game->textures.north_path = \
			ft_strtrim(skip_whitespace(line + 2), "\n");
		else if (ft_strncmp(line, "SO", 2) == 0)
			game->textures.south_path = \
			ft_strtrim(skip_whitespace(line + 2), "\n");
		else if (ft_strncmp(line, "WE", 2) == 0)
			game->textures.west_path = \
			ft_strtrim(skip_whitespace(line + 2), "\n");
		else if (ft_strncmp(line, "EA", 2) == 0)
			game->textures.east_path = \
			ft_strtrim(skip_whitespace(line + 2), "\n");
		else if (ft_strncmp(line, "F", 1) == 0)
			parse_color(skip_whitespace(line + 1), &game->floor_color);
		else if (ft_strncmp(line, "C", 1) == 0)
			parse_color(skip_whitespace(line + 1), &game->celing_color);
		free(line);
	}
	close(fd);
	return (extract_map(file, game), 0);
}
