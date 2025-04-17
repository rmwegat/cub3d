/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwegat <rwegat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:14:07 by rwegat            #+#    #+#             */
/*   Updated: 2025/04/17 15:36:23 by rwegat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (perror("Usage: ./cub3d <map_file>"), 1);
	if (parse_config(argv[1], &game))
	{
		ft_printf("parse_config failed!\n");
		return (1);
	}
    //debug
    ft_printf("North Texture: %s", game.textures.north);
    ft_printf("South Texture: %s", game.textures.south);
    ft_printf("West Texture: %s", game.textures.west);
    ft_printf("East Texture: %s\n", game.textures.east);
    ft_printf("Ceiling Color: R=%d, G=%d, B=%d, A=%d\n",
        game.celing_color.r, game.celing_color.g, game.celing_color.b, game.celing_color.a);
    ft_printf("Floor Color: R=%d, G=%d, B=%d, A=%d\n",
        game.floor_color.r, game.floor_color.g, game.floor_color.b, game.floor_color.a);
    ft_printf("\nMap:\n");
    for (int i = 0; game.map[i]; i++)
        ft_printf("%s", game.map[i]);
    //debug end
	return (0);
}