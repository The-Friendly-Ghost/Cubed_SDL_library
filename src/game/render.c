/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/18 20:44:01 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdint.h>

void	update(t_cub3d *cub3d_data)
{
	uint64_t	time_to_wait;
	float		delta_time;

	time_to_wait = FRAME_TIME_LENGTH - (SDL_GetTicks()
		- cub3d_data->game.ticks_last_frame);
	if (time_to_wait > 0 && time_to_wait <= FRAME_TIME_LENGTH)
		SDL_Delay(time_to_wait);
	delta_time = (SDL_GetTicks64() - cub3d_data->game.ticks_last_frame) / 1000.0f;
	(void)delta_time;
	cub3d_data->game.ticks_last_frame = SDL_GetTicks64();
}

void	render_frame(SDL_Renderer *render)
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);
	//TODO invoegen
	SDL_RenderPresent(render);
}