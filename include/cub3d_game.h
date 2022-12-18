/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_game.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/18 20:43:41 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H
# include "cub3d_structs.h"
# include <SDL2/SDL.h>
# include <stdbool.h>

/**
#=====================================#
#============ game_init.c ============#
#=====================================#
*/

/**
 * @brief Initiates the SDL Window and starts the game loop.
 * @param cub3d_data Pointer to the struct with the game data in it.
 * @return Nothing
 */
void	start_game(t_cub3d *cub3d_data);


/**
#=====================================#
#============== render.c =============#
#=====================================#
*/

/**
 * @brief Clear the new image and update the screen with any rendering
 * performed since the previous call.
 * @param render Pointer to a structure representing rendering state
 * @return Nothing
 */
void	render_frame(SDL_Renderer *render);

/**
 * @brief 
 * @param 
 * @return Nothing
 */
void	update(t_cub3d *cub3d_data);

/**
#=====================================#
#============== input.c ==============#
#=====================================#
*/

/**
 * @brief Checks if the player inputs anything (keystroke or press 'close')
 * @param running pointer to a bool that remains true while the game runs.
 * If the player presses 'Esc' or the close button, running becomes false.
 * @return Nothing
 */
void	get_input(t_game *game);

#endif