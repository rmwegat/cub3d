/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:10:22 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/30 18:38:59 by rwegat           ###   ########.fr       */
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
		if (line[j] != '1' && line[j] != '0' &&
			line[j] != 'N' && line[j] != 'S' &&
			line[j] != 'E' && line[j] != 'W' &&
			line[j] != ' ' && line[j] != '\n')
			return (0);
		j++;
	}
	return (1);
}

int	is_end_of_map_line(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != '1' && line[j] != ' ' && line[j] != '\n')
			return (0);
		j++;
	}
	return (1);
}
void	extract_map(char *file, t_game *game)
{
	int		fd;
	char	*line;
	int		i;
	int		is_map_started;

	i = 0;
	is_map_started = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error: Failed to open config file!"));
	game->map = malloc(sizeof(char *) * 1024);
	if (!game->map)
		return (close(fd), perror("Error: Map allocation failed!"));
	while ((line = get_next_line(fd)))
	{
		if (!is_map_started && is_valid_map_line(line))
			is_map_started = 1;

		if (is_map_started)
		{
			game->map[i] = ft_strdup(line);
			if (!game->map[i])
				return (close(fd), ft_free_map(game->map),
					perror("Error: Map line allocation failed!"));
			if (i > 0 && is_end_of_map_line(line))
			{
				free(line);
				i++;
				break;
			}
			free(line);
			i++;
		}
		else
			free(line);
	}
	game->map[i] = NULL;
	close(fd);
}
