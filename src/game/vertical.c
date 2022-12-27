/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vertical.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/27 14:13:49 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/27 15:59:43 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_structs.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"

void	get_vert_intercept(t_raycheck *vert, t_cub3d *cub3d,
			int strip_id)
{
	vert->next_touch_x = vert->x_intercept;
	vert->next_touch_y = vert->y_step;
	while (vert->next_touch_x >= 0
		&& vert->next_touch_x <= WINDOW_WIDTH
		&& vert->next_touch_y >= 0
		&& vert->next_touch_y <= WINDOW_HEIGTH)
	{
		vert->y_check = vert->next_touch_y;
		if (cub3d->rays[strip_id].is_ray_facing_left)
			vert->x_check = vert->next_touch_x - 1;
		else
			vert->x_check = vert->next_touch_x;
		if (check_wall_at(vert->x_check, vert->y_check, cub3d))
		{
			vert->wall_hit_x = vert->next_touch_x;
			vert->wall_hit_y = vert->next_touch_y;
			vert->found_wall_hit = true;
			vert->wall_hit_content = cub3d->map_data.map
			[(int)ft_floor(vert->y_check / cub3d->map_data.minimap_tile_size)]
			[(int)ft_floor(vert->x_check / cub3d->map_data.minimap_tile_size)];
			break ;
		}
		vert->next_touch_x += vert->x_step;
		vert->next_touch_y += vert->y_step;
	}
}

void	get_vertical_increment(t_raycheck *vert, t_cub3d *cub3d_data,
			int strip_id, float ray_angle)
{
	// Find the x-coordinate of the closest horiontal grid intersection
	vert->x_intercept = ft_floor(cub3d_data->player.x
			/ cub3d_data->map_data.minimap_tile_size)
		* cub3d_data->map_data.minimap_tile_size;
	if (cub3d_data->rays[strip_id].is_ray_facing_right)
		vert->x_intercept += cub3d_data->map_data.minimap_tile_size;
	// Find the y-coordinate of the closest horiontal grid intersection
	vert->y_intercept = cub3d_data->player.y + (vert->x_intercept
			- cub3d_data->player.x) * tan(ray_angle);
	// Calculate the increment xstep
	vert->x_step = cub3d_data->map_data.minimap_tile_size;
	if (cub3d_data->rays[strip_id].is_ray_facing_left)
		vert->x_step *= -1;
	// Calculate the increment ystep
	vert->y_step = cub3d_data->map_data.minimap_tile_size * tan(ray_angle);
	if (cub3d_data->rays[strip_id].is_ray_facing_up && vert->y_step > 0)
		vert->y_step *= -1;
	if (cub3d_data->rays[strip_id].is_ray_facing_down && vert->y_step < 0)
		vert->y_step *= -1;
	// PIKUMA 10 MIN
	get_vert_intercept(vert, cub3d_data, strip_id);
}
