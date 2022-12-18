/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/18 20:27:18 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <stdbool.h>


void	get_input(t_game *game)
{
	SDL_Event	event;

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		game->running = false;
	else if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			game->running = false;
	}
}
