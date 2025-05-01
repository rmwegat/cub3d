/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:17 by temil-da          #+#    #+#             */
/*   Updated: 2025/05/01 18:24:30 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include "../../include/cub3d.h"

void	init_game(t_game *game);
void    draw_rays(t_game *game);
void    handle_keystrokes(mlx_key_data_t data, void *param);
void    update_keystrokes(void *param);
void	move_player(t_game *game, float dx, float dy, bool *redraw);
void	norm_angle(float *angle);
void	ray_caster(t_game *game, float angle, int i);
void	draw_single_line(t_game *game, float dx, float dy, float distance);
void	draw_v_strip(t_game *game, float distance, int i);

char	**init_map(void);
void    draw_map(t_game *game);
void    draw_player(t_game *game);
void	init_player(t_player *player);
#endif