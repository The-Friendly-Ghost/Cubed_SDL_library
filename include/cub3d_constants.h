/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_constants.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/16 14:15:39 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/10 17:09:16 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CONSTANTS_H
# define CUB3D_CONSTANTS_H
# include <math.h>

# define WINDOW_WIDTH 1440
# define WINDOW_HEIGTH 1080

# define PI M_PI
# define TWO_PI (2 * M_PI)
# define TILE_SIZE 64
# define SCALE 0.3
# define FOV_ANGLE (60 * (TWO_PI / 360))
# define NUM_RAYS WINDOW_WIDTH

# define FPS 90
# define FRAME_TIME_LENGTH (1000 / FPS)

#endif