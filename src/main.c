/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/18 16:12:50 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window	*initialize_window(void)
{
	SDL_Window	*window;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		exit_error("SDL Init failed", 1);
	window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SDL_WINDOW_FULLSCREEN, SDL_WINDOW_FULLSCREEN, 0);
	if (window == NULL)
		exit_error("SDL Window Init failed", 1);
	return (window);
}

int	main(int argc, char **argv)
{
	t_cub3d		cub3d_data;
	SDL_Window	*window;

	(void)window;
	if (argc != 2)
		exit_error("Invalid amount of arguments", 1);
	init_map(&cub3d_data.map_data);
	parse_file(argv[1], &cub3d_data.map_data);
	validate_map(&cub3d_data.map_data);
	close(cub3d_data.map_data.fd_map);
	window = initialize_window();
	// while ("We have to pay taxes")
	// {
	// 	// process_input();
	// 	// update();
	// 	// render();
	// }
	return (1);
}
