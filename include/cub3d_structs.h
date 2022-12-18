/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_structs.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:48:32 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/18 20:42:23 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H
# include <stdbool.h>
# include <stdint.h>

/**
#=====================================#
#============== Structs ==============#
#=====================================#
*/

typedef struct s_rgb {
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_game {
	uint64_t	ticks_last_frame;
	bool		running;
}	t_game;

typedef struct s_map {
	char	**map;
	int		fd_map;
	int		n_row;
	int		n_column;
	char	*north_wall;
	char	*east_wall;
	char	*south_wall;
	char	*west_wall;
	t_rgb	*floor;
	t_rgb	*ceiling;
}	t_map;

typedef struct s_cub3d {
	t_map	map_data;
	t_game	game;
}	t_cub3d;

#endif
