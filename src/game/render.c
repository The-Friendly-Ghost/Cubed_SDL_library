/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/10 16:56:06 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "libft.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

bool	check_wall_at(float x, float y, t_cub3d *cub3d)
{
	int	grid_index_x;
	int	grid_index_y;

	if (x <= 0
		|| x >= TILE_SIZE * cub3d->map_data.n_column
		|| y <= 0
		|| y >= TILE_SIZE * cub3d->map_data.n_row)
		return (true);
	grid_index_x = (int)floor(x / TILE_SIZE);
	grid_index_y = (int)floor(y / TILE_SIZE);
	if (cub3d->map_data.map[grid_index_y][grid_index_x] == '1'
		|| cub3d->map_data.map[grid_index_y][grid_index_x] == ' ')
		return (true);
	else
		return (false);
}

void	move_player(float delta_time, t_cub3d *cub3d)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;

	cub3d->player.rotation_angle += cub3d->player.turn_direction
		* cub3d->player.turn_speed * delta_time;
	move_step = cub3d->player.walk_direction * cub3d->player.walk_speed
		* delta_time;
	new_player_x = cub3d->player.x + cos(cub3d->player.rotation_angle)
		* move_step;
	new_player_y = cub3d->player.y + sin(cub3d->player.rotation_angle)
		* move_step;
	if (check_wall_at(new_player_x, new_player_y, cub3d) == false)
	{
		cub3d->player.x = new_player_x;
		cub3d->player.y = new_player_y;
	}
}

void	cast_all_rays(t_cub3d *cub3d_data)
{
	float	ray_angle;
	int		strip_id;

	ray_angle = cub3d_data->player.rotation_angle - (FOV_ANGLE / 2);
	strip_id = 0;
	while (strip_id < NUM_RAYS)
	{
		cast_ray(cub3d_data, ray_angle, strip_id);
		ray_angle += (FOV_ANGLE / NUM_RAYS);
		strip_id++;
	}
}

void	update(t_cub3d *cub3d_data)
{
	uint64_t	time_to_wait;
	float		delta_time;

	time_to_wait = FRAME_TIME_LENGTH - (SDL_GetTicks()
			- cub3d_data->game.ticks_last_frame);
	if (time_to_wait > 0 && time_to_wait <= FRAME_TIME_LENGTH)
		SDL_Delay(time_to_wait);
	delta_time = (SDL_GetTicks64()
			- cub3d_data->game.ticks_last_frame) / 1000.0f;
	move_player(delta_time, cub3d_data);
	cub3d_data->game.ticks_last_frame = SDL_GetTicks64();
	cast_all_rays(cub3d_data);
}

void	render_frame(SDL_Renderer *render, t_cub3d *cub3d_data)
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	SDL_RenderClear(render);
	draw_background(render, cub3d_data);
	draw_minimap(render, cub3d_data);
	draw_rays(render, cub3d_data);
	SDL_RenderPresent(render);
}
