/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_game.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/19 17:20:14 by cpost         ########   odam.nl         */
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
 * @param cub3d_data Pointer to a structure with the game information in it
 * @return Nothing
 */
void	render_frame(SDL_Renderer *render, t_cub3d *cub3d_data);

/**
 * @brief 
 * @param cub3d_data Pointer to a structure with the game information in it
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
 * @param game 
 * @return Nothing
 */
void	get_input(t_cub3d *cub3d);

/**
#=====================================#
#=============== draw.c ==============#
#=====================================#
*/

/**
 * @brief Draws two rectangles on the screen. One on the upper half of the
 * screen (ceiling) and one on the lower half of the screen (floor). The
 * rgb-values for these rectangles are provided in the .cub file with 'F'
 * and 'C'.
 * @param cub3d_data Pointer to a structure with the game information in it
 * @param render Pointer to a structure representing rendering state
 * @return Nothing
 */
void	draw_background(SDL_Renderer *render, t_cub3d *cub3d_data);

/**
 * @brief Starts a while loop that loops over the entire map provided in
 * the .cub file. For every position in the map the function 'draw_tile'
 * is the called to draw a specific tile.
 * @param render Pointer to a structure representing rendering state
 * @param cub3d_data Pointer to a structure with the game information in it
 * @return Nothing
 */
void	draw_minimap(SDL_Renderer *render, t_cub3d *cub3d_data);

/**
 * @brief Function that draws each seperate tile of the minimap. The maximum
 * width and heigth of the minimap is set in CUB3D_CONSTANTS.H. According to
 * this max width and heigth a tile size was calculated in the function
 * 'init_structures' (game_init.c). With this tile size, this function prints
 * a tile on the screen. This means that a very large map will have a way
 * smaller tile size than a very small map.
 * @param render Pointer to a structure representing rendering state
 * @param cub3d_data Pointer to a structure with the game information in it
 * @param x The x coordinate of the tile that has to be printed on the map
 * @param y The y coordinate of the tile that has to be printed on the map
 * @return Nothing
 */
void	draw_tile(SDL_Renderer *render, t_cub3d *cub3d_data, int x, int y);

/**
 * @brief Draws a circle on the minimap where on the position where the player
 * is in the map.
 * @param render Pointer to a structure representing rendering state
 * @param cub3d_data Pointer to a structure with the game information in it
 * @return Nothing
 */
void	draw_player(SDL_Renderer *render, t_cub3d *cub3d_data);

#endif