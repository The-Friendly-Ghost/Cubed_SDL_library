/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/21 16:43:25 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_structs.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <math.h>

void	check_where_ray_is_facing(t_cub3d *cub3d_data, float ray_angle,
		int strip_id)
{
	if (ray_angle > 0 && ray_angle < PI)
	{
		cub3d_data->rays[strip_id].is_ray_facing_down = 1;
		cub3d_data->rays[strip_id].is_ray_facing_up = 0;
	}
	else
	{
		cub3d_data->rays[strip_id].is_ray_facing_down = 0;
		cub3d_data->rays[strip_id].is_ray_facing_up = 1;
	}
	if (ray_angle < 0.5 * PI && ray_angle > 1.5 * PI)
	{
		cub3d_data->rays[strip_id].is_ray_facing_right = 1;
		cub3d_data->rays[strip_id].is_ray_facing_left = 0;
	}
	else
	{
		cub3d_data->rays[strip_id].is_ray_facing_right = 0;
		cub3d_data->rays[strip_id].is_ray_facing_left = 1;
	}
}

float	normalize_angle(float ray_angle)
{
	ray_angle = ft_fmod(ray_angle, TWO_PI);
	if (ray_angle < 0)
		ray_angle = TWO_PI + ray_angle;
	return (ray_angle);
}

t_raycheck	check_horizontal_interception(t_raycheck *horz, t_cub3d *cub3d_data,
			int strip_id, float ray_angle)
{
	// Find the y-coordinate of the closest horiontal grid intersection
	horz->y_intercept = ft_floor(cub3d_data->player.y
			/ cub3d_data->map_data.minimap_tile_size)
		* cub3d_data->map_data.minimap_tile_size;
	if (cub3d_data->rays[strip_id].is_ray_facing_down)
		horz->wall_hit_y += cub3d_data->map_data.minimap_tile_size;
	// Find the x-coordinate of the closest horiontal grid intersection
	horz->x_intercept = cub3d_data->player.x + (horz->y_intercept
			- cub3d_data->player.y) / tan(ray_angle);
	// Calculate the increment ystep
	horz->y_step = cub3d_data->map_data.minimap_tile_size;
	if (cub3d_data->rays[strip_id].is_ray_facing_up)
		horz->y_step *= -1;
	// Calculate the increment xstep
	horz->x_step = cub3d_data->map_data.minimap_tile_size / tan(ray_angle);
	if (cub3d_data->rays[strip_id].is_ray_facing_left && horz->x_step > 0)
		horz->x_step *= -1;
	if (cub3d_data->rays[strip_id].is_ray_facing_right && horz->x_step < 0)
		horz->x_step *= -1;
	// PIKUMA 10 MIN
}

void	cast_ray(SDL_Renderer *render, t_cub3d *cub3d_data, float ray_angle,
		int strip_id)
{
	t_raycheck	vert;
	t_raycheck	horz;

	ray_angle = normalize_angle(ray_angle);
	check_where_ray_is_facing(cub3d_data, ray_angle, strip_id);
	check_horizontal_interception(&horz, cub3d_data, strip_id, ray_angle);
}
