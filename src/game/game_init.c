/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/18 17:22:46 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

SDL_Window	*initialize_window(void)
{
	SDL_Window	*window;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		exit_error("SDL Init failed", 1);
	window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGTH, SDL_WINDOW_BORDERLESS);
	if (window == NULL)
		exit_error("SDL Window Init failed", 1);
	return (window);
}

void	destroy_window(SDL_Renderer *render, SDL_Window *window)
{
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	check_game_state(bool *running)
{
	SDL_Event	event;

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		*running = false;
	else if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			*running = false;
	}
}

void	start_game(t_cub3d *cub3d_data)
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	bool			running;

	(void)cub3d_data;
	window = initialize_window();
	render = SDL_CreateRenderer(window, -1, 0);
	if (render == NULL)
		exit_error("SDL Window Init failed", 1);
	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
	running = true;
	while (running == true)
	{
		check_game_state(&running);
		// update();
		render_frame(render);
	}
	destroy_window(render, window);
}
