/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   horizontal.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 14:13:49 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/10 13:31:23 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_structs.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"
#include <math.h>

static void	set_horz_to_zero(t_raycheck *horz)
{
	horz->found_wall_hit = false;
	horz->wall_hit_x = 0;
	horz->wall_hit_y = 0;
	horz->wall_hit_content = 0;
	horz->distance = 0;
	horz->next_touch_x = 0;
	horz->next_touch_x = 0;
	horz->x_check = 0;
	horz->y_check = 0;
	horz->y_intercept = 0;
	horz->y_step = 0;
}

void	get_horz_intercept(t_raycheck *horz, t_cub3d *cub3d,
			int strip_id)
{
	horz->next_touch_x = horz->x_intercept;
	horz->next_touch_y = horz->y_intercept;
	while (check_within_bounds(horz, cub3d))
	{
		horz->x_check = horz->next_touch_x;
		if (cub3d->rays[strip_id].is_ray_facing_up)
			horz->y_check = horz->next_touch_y - 1;
		else
			horz->y_check = horz->next_touch_y;
		if (check_wall_at(horz->x_check, horz->y_check, cub3d))
		{
			horz->wall_hit_x = horz->next_touch_x;
			horz->wall_hit_y = horz->next_touch_y;
			horz->found_wall_hit = true;
			horz->wall_hit_content = cub3d->map_data.map
			[(int)floor(horz->y_check / TILE_SIZE)]
			[(int)floor(horz->x_check / TILE_SIZE)];
			break ;
		}
		horz->next_touch_x += horz->x_step;
		horz->next_touch_y += horz->y_step;
	}
}

void	get_horizontal_increment(t_raycheck *horz, t_cub3d *cub3d_data,
			int strip_id, float ray_angle)
{
	set_horz_to_zero(horz);
	// Find the y-coordinate of the closest horiontal grid intersection
	horz->y_intercept = floor(cub3d_data->player.y
			/ TILE_SIZE) * TILE_SIZE;
	if (cub3d_data->rays[strip_id].is_ray_facing_down)
		horz->y_intercept += TILE_SIZE;
	// Find the x-coordinate of the closest horiontal grid intersection
	horz->x_intercept = cub3d_data->player.x + (horz->y_intercept
			- cub3d_data->player.y) / tan(ray_angle);
	// Calculate the increment ystep
	horz->y_step = TILE_SIZE;
	if (cub3d_data->rays[strip_id].is_ray_facing_up)
		horz->y_step *= -1;
	// Calculate the increment xstep
	horz->x_step = TILE_SIZE / tan(ray_angle);
	if (cub3d_data->rays[strip_id].is_ray_facing_left && horz->x_step > 0)
		horz->x_step *= -1;
	if (cub3d_data->rays[strip_id].is_ray_facing_right && horz->x_step < 0)
		horz->x_step *= -1;
	get_horz_intercept(horz, cub3d_data, strip_id);
}
