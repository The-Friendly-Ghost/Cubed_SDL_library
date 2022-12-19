/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_constants.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:15:39 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/19 15:54:43 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CONSTANTS_H
# define CUB3D_CONSTANTS_H
# include <math.h>

#define WINDOW_WIDTH 1280.0
#define WINDOW_HEIGTH 960.0
#define MINIMAP_SIZE 620.0

#define PI M_PI
#define TWO_PI (2 * M_PI)
#define TILE_SIZE 64
#define FOV_ANGLE (60 * (TWO_PI / 360))
#define NUM_RAYS WINDOW_WIDTH

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#endif