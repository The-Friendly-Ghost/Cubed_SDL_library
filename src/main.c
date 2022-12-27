/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/27 15:21:13 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "cub3d_game.h"
#include "cub3d_constants.h"
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>

void	validate_constants(void)
{
	if (WINDOW_WIDTH < 800 || WINDOW_HEIGTH < 600)
		exit_error("Window be at least 800 [width] x 600 [height]", 1);
	if (WINDOW_WIDTH > 1440 || WINDOW_HEIGTH > 1080)
		exit_error("Window can be at most 1440 [width] x 1080 [height]", 1);
	if (WINDOW_WIDTH / 4 > (WINDOW_HEIGTH / 3) + 0.1
		|| WINDOW_WIDTH / 4 < (WINDOW_HEIGTH / 3) - 0.1)
		exit_error("Window aspect ratio must be 4:3", 1);
	if (FOV_ANGLE != (60 * (TWO_PI / 360)))
		exit_error("FOV must be 60 degrees (in radials)", 1);
	if (PI != M_PI || TWO_PI != 2 * M_PI)
		exit_error("Wait, you want to change pi??", 1);
	if (FPS < 24 || FPS > 120)
		exit_error("Keep FPS between 24 and 120", 1);
}

int	main(int argc, char **argv)
{
	t_cub3d			cub3d_data;

	if (argc != 2)
		exit_error("Invalid amount of arguments", 1);
	validate_constants();
	init_map(&cub3d_data.map_data);
	parse_file(argv[1], &cub3d_data.map_data);
	validate_map(&cub3d_data.map_data);
	start_game(&cub3d_data);
	close(cub3d_data.map_data.fd_map);
	return (1);
}
