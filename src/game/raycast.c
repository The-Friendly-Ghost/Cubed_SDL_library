/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/01 18:27:06 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d_structs.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <math.h>
#include <limits.h>

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
	if (ray_angle < 0.5 * PI || ray_angle > 1.5 * PI)
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

float	calc_distance_between_points(float x1, float y1, float x2, float y2)
{
	return (ft_sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	set_ray_distance(t_raycheck *vert, t_raycheck *horz,
		t_cub3d *cub3d_data, int strip_id)
{
	if (horz->found_wall_hit)
		horz->distance = calc_distance_between_points(cub3d_data->player.x,
				cub3d_data->player.x, horz->wall_hit_x, horz->wall_hit_y);
	else
		horz->distance = INT_MAX;
	if (vert->found_wall_hit)
		vert->distance = calc_distance_between_points(cub3d_data->player.x,
				cub3d_data->player.x, vert->wall_hit_x, vert->wall_hit_y);
	else
		vert->distance = INT_MAX;
	if (vert->distance < horz->distance)
	{
		cub3d_data->rays[strip_id].distance = vert->distance;
		cub3d_data->rays[strip_id].wall_hit_x = vert->wall_hit_x;
		cub3d_data->rays[strip_id].wall_hit_y = vert->wall_hit_y;
		cub3d_data->rays[strip_id].wall_hit_content = vert->wall_hit_content;
		cub3d_data->rays[strip_id].is_hit_vertical = true;
	}
	else
	{
		cub3d_data->rays[strip_id].distance = horz->distance;
		cub3d_data->rays[strip_id].wall_hit_x = horz->wall_hit_x;
		cub3d_data->rays[strip_id].wall_hit_y = horz->wall_hit_y;
		cub3d_data->rays[strip_id].wall_hit_content = horz->wall_hit_content;
		cub3d_data->rays[strip_id].is_hit_vertical = false;
	}
}

void	cast_ray(t_cub3d *cub3d_data, float ray_angle,
		int strip_id)
{
	// t_raycheck	vert;
	t_raycheck	horz;

	ray_angle = normalize_angle(ray_angle);
	check_where_ray_is_facing(cub3d_data, ray_angle, strip_id);
	get_horizontal_increment(&horz, cub3d_data, strip_id, ray_angle);
	// get_vertical_increment(&vert, cub3d_data, strip_id, ray_angle);
	// set_ray_distance(&vert, &horz, cub3d_data, strip_id);
	cub3d_data->rays[strip_id].ray_angle = ray_angle;
}
