/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_floor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/21 16:15:59 by cpost         #+#    #+#                 */
/*   Updated: 2022/12/21 16:21:05 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

/**
 * @brief The behaviour of this function is idential to the floor() function.
 * @param num The number to get the floor of
 * @return A double (the floor of num) or NaN
 * @note
 */
double	ft_floor(double num)
{
	long long	n;
	double		d;

	if (num >= LLONG_MAX || num <= LLONG_MIN || num != num)
		return (num);
	n = (long long)num;
	d = (double)n;
	if (d == num || num >= 0)
		return (d);
	else
		return (d - 1);
}

/**
 * @brief The behaviour of this function is idential to the floorf() function.
 * @param num The number to get the floor of
 * @return A float (the floor of num) or NaN
 * @note
 */
float	ft_floorf(float num)
{
	long long	n;
	float		d;

	if (num >= LLONG_MAX || num <= LLONG_MIN || num != num)
		return (num);
	n = (long long)num;
	d = (float)n;
	if (d == num || num >= 0)
		return (d);
	else
		return (d - 1);
}
