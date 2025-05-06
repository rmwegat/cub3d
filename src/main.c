/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rwegat <rwegat@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/02 18:14:07 by rwegat			#+#	#+#			 */
/*   Updated: 2025/04/30 18:35:36 by rwegat		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/cub3d.h"

// void print_debug(t_game *game)
// {
// 	ft_printf("North Texture Path: %s\n", game->textures.north_path);
// 	ft_printf("South Texture Path: %s\n", game->textures.south_path);
// 	ft_printf("West Texture Path: %s\n", game->textures.west_path);
// 	ft_printf("East Texture Path: %s\n", game->textures.east_path);
// 	ft_printf("Ceiling Color: R=%d, G=%d, B=%d, A=%d\n",
// 		game->celing_color.r, game->celing_color.g,
// 		game->celing_color.b, game->celing_color.a);
// 	ft_printf("Floor Color: R=%d, G=%d, B=%d, A=%d\n",
// 		game->floor_color.r, game->floor_color.g,
// 		game->floor_color.b, game->floor_color.a);
// 	ft_printf("\nMap:\n");
// 	for (int i = 0; game->map[i]; i++) {
// 		for (int j = 0; game->map[i][j]; j++) {
// 			if (game->map[i][j] == ' ')
// 				ft_printf("\033[31mx\033[0m");
// 			else if (game->map[i][j] == '0')
// 				ft_printf("\033[32mV\033[0m");
// 			else
// 				ft_printf("%c", game->map[i][j]);
// 		}
// 		ft_printf("\n");
// 	}
// 	ft_printf("Starting Direction: %c\n", game->starting_direction);
// 	printf("Player Position: X=%.2f, Y=%.2f\n",
// 		game->player->x, game->player->y);
// 	printf("Player Angle: %.2f\n", game->player->angle);
// }

void	ft_leaks(void)
{
	system("leaks cub3D");
}

// atexit(ft_leaks);
int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (perror("Usage: ./cub3d <map_file>"), 1);
	if (ft_alloc_game(&game))
		return (1);
	if (parse_config(argv[1], game))
		return (ft_free_game(game), 1);
	init(game);
	init_game(game);
	draw_rays(game);
	mlx_loop_hook(game->mlx, &update_keystrokes, game);
	mlx_loop(game->mlx);
	ft_free_game(game);
	return (0);
}
