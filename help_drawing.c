/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:38:07 by icanker           #+#    #+#             */
/*   Updated: 2020/02/04 17:38:12 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		find_max(float x_size, float y_size)
{
	return (x_size > y_size) ? x_size : y_size;
}

float		find_mod(float x_size)
{
	return (x_size < 0) ? (x_size * (-1)) : x_size;
}

void		ft_swap(float *num_0, float *num_1)
{
	float num_2;

	num_2 = *num_0;
	*num_0 = *num_1;
	*num_1 = num_2;
}

void		init_z(float z, float z1, t_dpoint *pts)
{
	pts->z = z * SCALE;
	pts->z1 = z1 * SCALE;
}

t_dpoint	init_pts(float x, float x1, float y, float y1)
{
	t_dpoint pts;

	pts.x = x;
	pts.y = y;
	pts.x1 = x1;
	pts.y1 = y1;
	return (pts);
}
