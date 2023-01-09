/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 15:09:07 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/09 16:55:02 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d_constants.h"
#include "cub3d_structs.h"

float	normalize_angle(float ray_angle)
{
	if (ray_angle > TWO_PI)
		ray_angle = fmod(ray_angle, TWO_PI);
	if (ray_angle < 0)
		ray_angle = TWO_PI + ray_angle;
	return (ray_angle);
}

int	check_within_bounds(t_raycheck *ray, t_cub3d *cub3d)
{
	if (ray->next_touch_x >= 0
		&& ray->next_touch_x
		<= cub3d->map_data.minimap_tile_size * cub3d->map_data.n_column
		&& ray->next_touch_y >= 0
		&& ray->next_touch_y
		<= cub3d->map_data.minimap_tile_size * cub3d->map_data.n_row)
		return (1);
	return (0);
}
