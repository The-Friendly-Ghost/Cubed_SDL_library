/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_game.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 11:13:37 by cpost         #+#    #+#                 */
/*   Updated: 2023/01/10 16:55:50 by cpost         ########   odam.nl         */
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
void		start_game(t_cub3d *cub3d_data);

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
void		render_frame(SDL_Renderer *render, t_cub3d *cub3d_data);

/**
 * @brief 
 * @param cub3d_data Pointer to a structure with the game information in it
 * @return Nothing
 */
void		update(t_cub3d *cub3d_data);

/**
 * @brief Checks whether a x and y position contains a wall or not.
 * @param x The x coordinate to check
 * @param y The y coordinate to check
 * @param cub3d_data Pointer to a structure with the game information in it
 * @return True if coordinate contains a wall or empty space. 
 * False if this is not the case.
 */
bool		check_wall_at(float x, float y, t_cub3d *cub3d);

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
void		get_input(t_cub3d *cub3d);

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
void		draw_background(SDL_Renderer *render, t_cub3d *cub3d_data);

/**
 * @brief Starts a while loop that loops over the entire map provided in
 * the .cub file. For every position in the map the function 'draw_tile'
 * is the called to draw a specific tile.
 * @param render Pointer to a structure representing rendering state
 * @param cub3d_data Pointer to a structure with the game information in it
 * @return Nothing
 */
void		draw_minimap(SDL_Renderer *render, t_cub3d *cub3d_data);

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
void		draw_tile(SDL_Renderer *render, t_cub3d *cub3d_data, int x, int y);

/**
 * @brief Draws a circle on the minimap where on the position where the player
 * is in the map.
 * @param render Pointer to a structure representing rendering state
 * @param cub3d_data Pointer to a structure with the game information in it
 * @return Nothing
 */
void		draw_rays(SDL_Renderer *render, t_cub3d *cub3d_data);

/**
#=====================================#
#=========== horizontal.c ============#
#=====================================#
*/

/**
 * @brief Determines the x_step and y_step that are needed to look for
 * the horizontal wallhits of a ray.
 * @param horz Pointer to structure with information about a specific ray
 * @param cub3d_data Pointer to a structure with the game information in it
 * @param strip_id The id of the ray to check
 * @param ray_angle The angle of the ray to check
 * @return A structure with information about a specific ray
 */
void		get_horizontal_increment(t_raycheck *horz,
				t_cub3d *cub3d_data, int strip_id, float ray_angle);

/**
 * @brief Determines if and where a ray intercepts with a wall on the
 * horizontal axis
 * @param horz Pointer to structure with information about a specific ray
 * @param cub3d_data Pointer to a structure with the game information in it
 * @param strip_id The id of the ray to check
 * @return Nothing
 */
void		get_horz_intercept(t_raycheck *horz, t_cub3d *cub3d,
				int strip_id);

/**
#=====================================#
#============ vertical.c =============#
#=====================================#
*/

/**
 * @brief Determines the x_step and y_step that are needed to look for
 * the vertical wallhits of a ray.
 * @param vert Pointer to structure with information about a specific ray
 * @param cub3d_data Pointer to a structure with the game information in it
 * @param strip_id The id of the ray to check
 * @param ray_angle The angle of the ray to check
 * @return A structure with information about a specific ray
 */
void		get_vertical_increment(t_raycheck *vert,
				t_cub3d *cub3d_data, int strip_id, float ray_angle);

/**
 * @brief Determines if and where a ray intercepts with a wall on the
 * vertical axis
 * @param vert Pointer to structure with information about a specific ray
 * @param cub3d_data Pointer to a structure with the game information in it
 * @param strip_id The id of the ray to check
 * @return Nothing
 */
void		get_vert_intercept(t_raycheck *vert, t_cub3d *cub3d,
				int strip_id);

/**
#=====================================#
#============ raycast.c =============#
#=====================================#
*/

/**
 * @brief
 * @param
 * @return
 */
void		cast_ray(t_cub3d *cub3d_data, float ray_angle,
				int strip_id);

/**
#=====================================#
#============== utils.c ==============#
#=====================================#
*/

/**
 * @brief Normalizes an angle so that it is always between 0 and 360 degrees.
 * If an angle is 361 for example, this function normalizes it to 1 degree.
 * @param ray_angle The angle to check
 * @return The normalized angle
 */
float		normalize_angle(float ray_angle);

/**
 * @brief Checks whether a raycheck is within bounds of the map.
 * @param ray The ray to check
 * @param cub3d Pointer to a structure with the game information in it
 * @return 1 if true (within bounds), 0 if false (out of bounds)
 */
int			check_within_bounds(t_raycheck *ray, t_cub3d *cub3d);

#endif