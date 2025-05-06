/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:10:22 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/06 20:08:35 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void	handle_map_line(char *line, t_game *game, int *is_map_started, int *i)
{
	if (!(*is_map_started) && is_valid_map_line(line))
		*is_map_started = 1;
	if (*is_map_started)
	{
		game->map[*i] = ft_strdup(line);
		if (!game->map[*i])
		{
			free(line);
			return (ft_free_map(&game->map),
				perror("Error: Map line allocation failed!"));
		}
		(*i)++;
	}
	free(line);
}

void	read_map_lines(int fd, t_game *game, int *is_map_started)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		handle_map_line(line, game, is_map_started, &i);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
}

int	count_map_rows(char *file)
{
	int		fd;
	int		row_count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error: Failed to open config file!"), -1);
	row_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 0 && is_valid_map_line(line))
			row_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (row_count);
}

void	extract_map(char *file, t_game *game)
{
	int	fd;
	int	is_map_started;
	int	row_count;
	int	i;

	is_map_started = 0;
	row_count = count_map_rows(file);
	if (row_count <= 0)
		return (perror("Error: Invalid or empty map!"));
	game->map = malloc(sizeof(char *) * (row_count + 1));
	if (!game->map)
		return (perror("Error: Map allocation failed!"));
	i = 0;
	while (i <= row_count)
	{
		game->map[i] = NULL;
		i++;
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error: Failed to reopen config file!"));
	read_map_lines(fd, game, &is_map_started);
	close(fd);
}
