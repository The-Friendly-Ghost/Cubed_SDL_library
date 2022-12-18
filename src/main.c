/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/18 16:46:30 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_utils.h"
#include "cub3d_structs.h"
#include "cub3d_game.h"
#include "libft.h"
#include <stdbool.h>
#include <unistd.h>


int	main(int argc, char **argv)
{
	t_cub3d			cub3d_data;

	if (argc != 2)
		exit_error("Invalid amount of arguments", 1);
	init_map(&cub3d_data.map_data);
	parse_file(argv[1], &cub3d_data.map_data);
	validate_map(&cub3d_data.map_data);
	start_game(&cub3d_data);
	close(cub3d_data.map_data.fd_map);
	return (1);
}
