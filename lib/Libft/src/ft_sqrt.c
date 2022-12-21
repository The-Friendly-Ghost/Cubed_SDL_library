/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 15:22:58 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/21 15:54:25 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

/**
 * @brief The behaviour of this function is idential to the sqrt() function.
 * @param num The number to check the square root of
 * @return A double (the square root of num) or NaN if num = negative
 * @note
 */
double	ft_sqrt(double num)
{
	double	sqrt;
	double	temp;

	if (num < 0)
		return (NAN);
	sqrt = num / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (num / temp + temp) / 2;
	}
	return (sqrt);
}

/**
 * @brief The behaviour of this function is idential to the sqrtf() function.
 * @param num The number to check the square root of
 * @return A float (the square root of num) or NaN if num = negative
 * @note
 */
float	ft_sqrtf(float num)
{
	float	sqrt;
	float	temp;

	if (num < 0)
		return (NAN);
	sqrt = num / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (num / temp + temp) / 2;
	}
	return (sqrt);
}
