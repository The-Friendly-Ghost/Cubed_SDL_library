/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 08:58:25 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/21 15:46:27 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"
#include "cub3d_constants.h"
#include "cub3d_game.h"
#include <SDL2/SDL.h>
#include <math.h>

void	draw_player(SDL_Renderer *render, t_cub3d *cub3d_data)
{
	// float	ray_angle;
	// int		strip_id;

	// ray_angle = cub3d_data->player.rotation_angle - (FOV_ANGLE / 2);
	// while (strip_id < NUM_RAYS)
	// {
	// 	cast_ray(render, cub3d_data, ray_angle, strip_id);
	// 	ray_angle += FOV_ANGLE / NUM_RAYS;
	// 	strip_id++;
	// }

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
	SDL_RenderDrawLine(render, cub3d_data->player.x, cub3d_data->player.y,
		cub3d_data->player.x + cos(cub3d_data->player.rotation_angle) * 40,
		cub3d_data->player.y + sin(cub3d_data->player.rotation_angle) * 40);
}

void	draw_tile(SDL_Renderer *render, t_cub3d *cub3d_data, int x, int y)
{
	float		pos_x;
	float		pos_y;
	SDL_Rect	tile;

	pos_x = (float)x * cub3d_data->map_data.minimap_tile_size;
	pos_y = (float)y * cub3d_data->map_data.minimap_tile_size;
	if (cub3d_data->map_data.map[y][x] == '1')
		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	else if (cub3d_data->map_data.map[y][x] == ' ')
		SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
	else
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	tile.x = pos_x;
	tile.y = pos_y;
	tile.h = cub3d_data->map_data.minimap_tile_size + 1;
	tile.w = cub3d_data->map_data.minimap_tile_size + 1;
	SDL_RenderFillRect(render, &tile);
}

void	draw_minimap(SDL_Renderer *render, t_cub3d *cub3d_data)
{
	int	y;
	int	x;

	y = 0;
	while (cub3d_data->map_data.map[y])
	{
		x = 0;
		while (cub3d_data->map_data.map[y][x])
		{
			draw_tile(render, cub3d_data, x, y);
			x++;
		}
		y++;
	}
}

void	draw_background(SDL_Renderer *render, t_cub3d *cub3d_data)
{
	SDL_Rect	floor;
	SDL_Rect	ceiling;

	SDL_SetRenderDrawColor(render, cub3d_data->map_data.floor->red,
		cub3d_data->map_data.floor->green, cub3d_data->map_data.floor->blue,
		255);
	floor.x = 0;
	floor.y = WINDOW_HEIGTH / 2;
	floor.w = WINDOW_WIDTH;
	floor.h = WINDOW_HEIGTH / 2;
	SDL_RenderFillRect(render, &floor);
	SDL_SetRenderDrawColor(render, cub3d_data->map_data.ceiling->red,
		cub3d_data->map_data.ceiling->green, cub3d_data->map_data.ceiling->blue,
		255);
	ceiling.x = 0;
	ceiling.y = 0;
	ceiling.w = WINDOW_WIDTH;
	ceiling.h = WINDOW_HEIGTH / 2;
	SDL_RenderFillRect(render, &ceiling);
}
