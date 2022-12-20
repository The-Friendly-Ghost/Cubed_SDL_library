/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/20 09:46:45 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

void	get_input(t_cub3d *cub3d)
{
	SDL_Event	event;

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		cub3d->game.running = false;
	else if (event.type == SDL_KEYUP)
	{
		if (event.key.keysym.sym == SDLK_UP)
			cub3d->player.walk_direction = 0;
		else if (event.key.keysym.sym == SDLK_DOWN)
			cub3d->player.walk_direction = 0;
		else if (event.key.keysym.sym == SDLK_RIGHT)
			cub3d->player.turn_direction = 0;
		else if (event.key.keysym.sym == SDLK_LEFT)
			cub3d->player.turn_direction= 0;
	}
	else if (event.type == SDL_KEYDOWN && !event.key.repeat)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			cub3d->game.running = false;
		else if (event.key.keysym.sym == SDLK_UP)
			cub3d->player.walk_direction = +1;
		else if (event.key.keysym.sym == SDLK_DOWN)
			cub3d->player.walk_direction = -1;
		else if (event.key.keysym.sym == SDLK_RIGHT)
			cub3d->player.turn_direction = -1;
		else if (event.key.keysym.sym == SDLK_LEFT)
			cub3d->player.turn_direction= +1;
	}
}
