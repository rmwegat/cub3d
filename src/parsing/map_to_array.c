/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:10:22 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/09 14:00:25 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_map_dimensions(char *file, int *rows, int *cols)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	*rows = 0;
	*cols = 0;
	while ((line = get_next_line(fd)))
	{
		len = ft_strlen(line);
		if (len > *cols)
			*cols = len;
		(*rows)++;
		free(line);
	}
	close(fd);
	return (0);
}

static char	*allocate_and_fill_line(char *line, int cols)
{
	int		j;
	char	*map_line;

	map_line = malloc(sizeof(char) * (cols + 1));
	if (!map_line)
		return (NULL);
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (line[j] == ' ' || line[j] == '\t')
			map_line[j] = 'X';
		else
			map_line[j] = line[j];
		j++;
	}
	while (j < cols)
		map_line[j++] = 'X';
	map_line[j] = '\0';
	return (map_line);
}

static char	**allocate_map(int rows, int cols, int fd)
{
	int		i;
	char	*line;
	char	**map;

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

char	**config_to_array(char *file)
{
	int		fd;
	int		rows;
	int		cols;
	char	**map;

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
// 		ft_printf("Usage: %s <map_file>\n", argv[0]);
// 		return (1);
// 	}
// 	char **map = config_to_array(argv[1]);
// 	if (!map)
// 		return (ft_printf("Error: Failed to parse the map file.\n"));
// 	for (int i = 0; map[i]; i++)
// 	{
// 		for (int j = 0; map[i][j]; j++)
// 		{
// 			if (map[i][j] == 'X')
// 				write(1, "\033[31mX\033[0m", 11);
// 			else
// 				ft_printf("%c", map[i][j]);
// 		}
// 		ft_printf("\n");
// 		free(map[i]);
// 	}
// 	free(map);
// 	return (0);
// }
