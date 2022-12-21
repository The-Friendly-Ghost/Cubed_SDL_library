/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fmod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/06 14:37:46 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/21 12:35:23 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The normal modulo operator doesn't work with floats. To calculate
 * the remainder of two floats, one can use the function 'fmod()' or
 * 'remainder()'. However, since those are not allowed in the 42 projects, I
 * made my own function to find the remainder of two floats. The parameters
 * are inputted as followes : a % b 
 * @param a The first number
 * @param b The second number
 * @return A float
 * @note It is possible to input one or two integers a parameters as well.
 * However, the return value will be a float.
 */
float	ft_fmod(float a, float b)
{
	float	mod;

	if (a < 0)
		mod = -a;
	else
		mod = a;
	if (b < 0)
		b = -b;
	while (mod >= b)
		mod = mod - b;
	if (a < 0)
		return (-mod);
	return (mod);
}
