/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temil-da <temil-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:17 by temil-da          #+#    #+#             */
/*   Updated: 2025/04/11 16:34:53 by temil-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include "../../include/cub3d.h"

void	init_game(t_game *game);
char	**init_map(void);
void    draw_map(t_game *game);
void    draw_player(t_game *game);

#endif