/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_game.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/18 17:00:39 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H
# include "cub3d_structs.h"
# include <SDL2/SDL.h>

/**
#=====================================#
#============ game_init.c ============#
#=====================================#
*/

/**
 * @brief Initiates the SDL Window and starts the game loop.
 * @param cub3d_data Pointer to the struct with the game data in it.
 * @return Nothing
 * @note
 */
void	start_game(t_cub3d *cub3d_data);


/**
#=====================================#
#============== render.c =============#
#=====================================#
*/

/**
 * @brief 
 * @param render Pointer to a structure representing rendering state
 * @return Nothing
 * @note
 */
void	render_frame(SDL_Renderer *render);

#endif