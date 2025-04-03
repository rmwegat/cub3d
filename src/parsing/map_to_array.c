/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:10:22 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/03 16:19:31 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int get_map_dimensions(char *file, int *rows, int *cols)
{
	int fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	char *line;
	*rows = 0;
	*cols = 0;
	while ((line = get_next_line(fd)))
	{
		int len = ft_strlen(line);
		if (len > *cols)
			*cols = len;
		(*rows)++;
		free(line);
	}
	close(fd);
	return (0);
}

static char *allocate_and_fill_line(char *line, int cols)
{
	int j;
	char *map_line;

	map_line = malloc(sizeof(char) * (cols + 1));
	if (!map_line)
		return (NULL);
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		map_line[j] = (line[j] == ' ') ? 'X' : line[j];
		j++;
	}
	while (j < cols)
		map_line[j++] = 'X';
	map_line[j] = '\0';
	return (map_line);
}

static char **allocate_map(int rows, int cols, int fd)
{
	char **map;
	char *line;
	int i;

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		map[i] = allocate_and_fill_line(line, cols);
		free(line);
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

char **map_to_array(char *file)
{
	int rows;
	int cols;
	int fd;
	char **map;

	rows = 0;
	cols = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0 || get_map_dimensions(file, &rows, &cols) < 0)
		return (NULL);
	map = allocate_map(rows, cols, fd);
	close(fd);
	return (map);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		ft_printf(stderr, "Usage: %s <map_file>\n", argv[0]);
// 		return (1);
// 	}
// 	char **map = map_to_array(argv[1]);
// 	if (!map)
// 	{
// 		ft_printf(stderr, "Error: Failed to parse the map file.\n");
// 		return (1);
// 	}
// 	for (int i = 0; map[i]; i++)
// 	{
// 		ft_printf("%s\n", map[i]);
// 		free(map[i]);
// 	}
// 	free(map);
// 	return (0);
// }