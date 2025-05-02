/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:34:36 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/30 18:41:03 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_textures(t_textures *textures)
{
	if (!textures)
		return;
	free(textures->north);
	free(textures->south);
	free(textures->west);
	free(textures->east);
}

void	ft_free_game(t_game *game)
{
	if (!game)
		return;
	ft_free_map(game->map);
	ft_free_textures(&game->textures);
	free(game);
}

int	ft_alloc_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (perror("Error: Failed to allocate t_game structure!"), 1);
	(*game)->map = NULL;
	(*game)->textures.north = NULL;
	(*game)->textures.south = NULL;
	(*game)->textures.west = NULL;
	(*game)->textures.east = NULL;
	return (0);
}

int	ft_alloc_map(char ***map)
{
	*map = malloc(sizeof(char *) * 1024);
	if (!*map)
		return (perror("Error: Failed to allocate map!"), 1);
	return (0);
}
