/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/20 15:14:38 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d_structs.h"
// #include "cub3d_constants.h"
// #include "cub3d_game.h"
// #include <SDL2/SDL.h>
// #include <math.h>
// #include <stdio.h>

// void	draw_player(SDL_Renderer *render, t_cub3d *cub3d_data)
// {
// 	SDL_Rect	player;

// 	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
// 	player.x = cub3d_data->player.x;
// 	player.y = cub3d_data->player.y;
// 	player.h = cub3d_data->player.height;
// 	player.w = cub3d_data->player.width;
// 	SDL_RenderDrawLine(render, player.x, player.y,
// 		player.x + cos(cub3d_data->player.rotation_angle) * 40,
// 		player.y + sin(cub3d_data->player.rotation_angle) * 40);
// }