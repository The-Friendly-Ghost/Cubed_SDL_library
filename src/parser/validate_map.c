/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/07 12:33:22 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/10 15:13:15 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_parser.h"
#include "cub3d_structs.h"
#include "cub3d_utils.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void	check_if_map_is_closed(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '0')
			{
				if (x == 0 || y == 0 || map->map[y + 1] == NULL
					|| map->map[y][x + 1] == '\0')
					exit_error("Map not enclosed by walls", 1);
				if (map->map[y - 1][x] == ' ' || map->map[y + 1][x] == ' '
					|| map->map[y][x - 1] == ' ' || map->map[y][x + 1] == ' ')
					exit_error("Map not enclosed by walls", 1);
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief Equalizes all rows to the same length.
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
static void	equalize_row_length(t_map *map)
{
	unsigned long	len;
	int				i;

	i = 0;
	len = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) > len)
			len = ft_strlen(map->map[i]);
		i++;
	}
	i = 0;
	while (map->map[i])
	{
		map->map[i] = ft_strfill(map->map[i], len, ' ');
		i++;
	}
	map->n_column = len;
}

static void	check_forbidden_characters_in_map(t_map *map)
{
	bool	player_init;
	int		y;
	int		x;

	player_init = false;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'W' || map->map[y][x] == 'E')
			{
				if (player_init == true)
					exit_error("Only 1 player allowed in map", 1);
				player_init = true;
				map->starting_orientation = map->map[y][x];
				map->start_pos_x = x;
				map->start_pos_y = y;
			}
			else if (map->map[y][x] != '1' && map->map[y][x] != '0'
				&& map->map[y][x] != ' ')
				exit_error("Forbidden characters in map", 1);
			x++;
		}
		y++;
	}
}

/**
 * @brief First, removes all the lines that contain only whitespaces off the 
 * bottom of the map. Then, checks if there is a line with only whitespaces
 * somewhere inside of the map. If that is the case, the program exits.
 * @param map Pointer to the struct that has all the map information in it
 * @return Nothing
 * @note
 */
static void	check_empty_lines(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		i++;
	i--;
	while (ft_str_is_whitespace(map->map[i]))
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i--;
	}
	i = 0;
	while (map->map[i])
	{
		if (ft_str_is_whitespace(map->map[i]))
			exit_error("No empty lines inside of the map allowed", 1);
		i++;
	}
}

void	validate_map(t_map *map)
{
	check_empty_lines(map);
	equalize_row_length(map);
	check_forbidden_characters_in_map(map);
	check_if_map_is_closed(map);
	if (map->n_column * TILE_SIZE * SCALE > WINDOW_WIDTH
		|| map->n_row * TILE_SIZE * SCALE > WINDOW_HEIGTH)
		exit_error("Minimap is larger than window", 1);
}
