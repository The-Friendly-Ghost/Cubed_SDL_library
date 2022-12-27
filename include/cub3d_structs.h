/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_structs.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:48:32 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/27 14:39:24 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H
# include "cub3d_constants.h"
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
	char	starting_orientation;
	float	start_pos_x;
	float	start_pos_y;
	float	minimap_tile_size;
	float	scale_factor;
	char	*north_wall;
	char	*east_wall;
	char	*south_wall;
	char	*west_wall;
	t_rgb	*floor;
	t_rgb	*ceiling;
}	t_map;

typedef struct s_player {
	float		x;
	float		y;
	float		height;
	float		width;
	int			turn_direction;
	int			walk_direction;
	float		rotation_angle;
	float		walk_speed;
	float		turn_speed;
}	t_player;

typedef struct s_rays {
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			is_hit_vertical;
	int			is_ray_facing_down;
	int			is_ray_facing_up;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
	int			wall_hit_content;
}	t_rays[NUM_RAYS];

typedef struct s_raycheck {
	float	distance;
	bool	found_wall_hit;
	float	wall_hit_x;
	float	wall_hit_y;
	float	wall_hit_content;
	float	x_step;
	float	y_step;
	float	x_intercept;
	float	y_intercept;
	float	next_touch_x;
	float	next_touch_y;
	float	x_check;
	float	y_check;
}	t_raycheck;

typedef struct s_cub3d {
	t_map		map_data;
	t_game		game;
	t_player	player;
	t_rays		rays;
}	t_cub3d;

#endif
