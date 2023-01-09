/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/09 17:14:59 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <unistd.h>

SDL_Window	*initialize_window(void)
{
	SDL_Window	*window;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		exit_error("SDL Init failed", 1);
	window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGTH,
			SDL_WINDOW_BORDERLESS);
	if (window == NULL)
		exit_error("SDL Window Init failed", 1);
	return (window);
}

void	set_player_starting_position(t_cub3d *cub3d)
{
	cub3d->player.y = cub3d->map_data.minimap_tile_size
		* cub3d->map_data.start_pos_y;
	cub3d->player.x = cub3d->map_data.minimap_tile_size
		* cub3d->map_data.start_pos_x;
	if (cub3d->map_data.n_column > cub3d->map_data.n_row)
	{
		cub3d->player.width = 100 / cub3d->map_data.n_column + 2;
		cub3d->player.height = 100 / cub3d->map_data.n_column + 2;
	}
	else
	{
		cub3d->player.width = 100 / cub3d->map_data.n_row + 2;
		cub3d->player.height = 100 / cub3d->map_data.n_row + 2;
	}
}

void	init_structures(t_cub3d *cub3d)
{
	cub3d->game.running = true;
	cub3d->game.ticks_last_frame = SDL_GetTicks64();
	cub3d->player.turn_direction = 0;
	cub3d->player.walk_direction = 0;
	cub3d->player.turn_speed = 120 * (TWO_PI / 360);
	if (cub3d->map_data.starting_orientation == 'E')
		cub3d->player.rotation_angle = TWO_PI * 0;
	else if (cub3d->map_data.starting_orientation == 'S')
		cub3d->player.rotation_angle = TWO_PI * 0.25;
	else if (cub3d->map_data.starting_orientation == 'W')
		cub3d->player.rotation_angle = TWO_PI * 0.5;
	else
		cub3d->player.rotation_angle = TWO_PI * 0.75;
	if (cub3d->map_data.n_column > cub3d->map_data.n_row)
		cub3d->map_data.minimap_tile_size = (MINIMAP_SIZE
				/ cub3d->map_data.n_column);
	else
		cub3d->map_data.minimap_tile_size = (MINIMAP_SIZE
				/ cub3d->map_data.n_row);
	cub3d->player.walk_speed = 3 * cub3d->map_data.minimap_tile_size;
	set_player_starting_position(cub3d);
}

void	destroy_window(SDL_Renderer *render, SDL_Window *window)
{
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void	start_game(t_cub3d *cub3d_data)
{
	SDL_Window		*window;
	SDL_Renderer	*render;

	window = initialize_window();
	render = SDL_CreateRenderer(window, -1, 0);
	if (render == NULL)
		exit_error("SDL Window Init failed", 1);
	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
	init_structures(cub3d_data);
	while (cub3d_data->game.running == true)
	{
		get_input(cub3d_data);
		update(cub3d_data);
		render_frame(render, cub3d_data);
		usleep(200);
	}
	destroy_window(render, window);
}
