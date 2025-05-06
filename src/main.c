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

void	ft_leaks(void)
{
	system("leaks cub3D");
}

//atexit(ft_leaks);
int	main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2)
		return (perror("Usage: ./cub3d <map_file>"), 1);
	if (ft_alloc_game(&game))
		return (1);
	if (parse_config(argv[1], game))
		return (ft_free_game(game, false), 1);
	init(game);
	init_game(game);
	draw_rays(game);
	mlx_loop_hook(game->mlx, &update_keystrokes, game);
	mlx_close_hook(game->mlx, &close_hook, game);
	mlx_loop(game->mlx);
	ft_free_game(game, true);
	return (0);
}
