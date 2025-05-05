/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:34:36 by rwegat            #+#    #+#             */
/*   Updated: 2025/05/05 15:47:24 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
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
		return ;
	free(textures->north_path);
	free(textures->south_path);
	free(textures->west_path);
	free(textures->east_path);
}

void	ft_free_game(t_game *game)
{
	if (!game)
		return ;
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
	(*game)->textures.north_path = NULL;
	(*game)->textures.south_path = NULL;
	(*game)->textures.west_path = NULL;
	(*game)->textures.east_path = NULL;
	(*game)->image = NULL;
	(*game)->mlx = NULL;
	(*game)->player = malloc(sizeof(t_player));
	if (!(*game)->player)
		return (perror("Error: Failed to allocate t_player structure!"), 1);
	(*game)->player->x = 0;
	(*game)->player->y = 0;
	(*game)->player->angle = 0;
	return (0);
}

int	ft_alloc_map(char ***map)
{
	*map = malloc(sizeof(char *) * 1024);
	if (!*map)
		return (perror("Error: Failed to allocate map!"), 1);
	return (0);
}
