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

void	ft_free_map(char ***map)
{
	int	i;

	if (!map || !*map)
		return ;
	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

void	ft_free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	free(textures->north_path);
	free(textures->south_path);
	free(textures->west_path);
	free(textures->east_path);
	if (textures->east_texture)
		mlx_delete_texture(textures->east_texture);
	if (textures->north_texture)
		mlx_delete_texture(textures->north_texture);
	if (textures->south_texture)
		mlx_delete_texture(textures->south_texture);
	if (textures->west_texture)
		mlx_delete_texture(textures->west_texture);
	textures->south_path = NULL;
	textures->north_path = NULL;
	textures->east_path = NULL;
	textures->west_path = NULL;
	textures->east_texture = NULL;
	textures->north_texture = NULL;
	textures->south_texture = NULL;
	textures->west_texture = NULL;
}

void	ft_free_game(t_game *game, bool terminate)
{
	if (!game)
		return ;
	ft_free_map(&game->map);
	ft_free_textures(&game->textures);
	if (game->mlx)
	{
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		if (game->mlx->window)
			mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
	}
	if (game->player)
		free(game->player);
	free(game);
	if (terminate)
		exit(EXIT_SUCCESS);
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
