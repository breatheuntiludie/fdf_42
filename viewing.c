/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:20:12 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/03 19:24:47 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling(float *x, float *y, float *x1, float *y1)
{
	*x *= SCALE;
	*y *= SCALE;
	*x1 *= SCALE;
	*y1 *= SCALE;
}

void	iso(float *x, float *y, int z, t_map *map)
{
	float	x_0;
	float	y_0;

	if (map->code == 1)
	{
		y_0 = *y;
		x_0 = *x;
		y_0 -= map->y / 2 * SCALE;
		*x = (x_0 - y_0) * cos(30 * 3.14 / 180);
		*y = (x_0 + y_0) * sin(30 * 3.14 / 180) - z;
	}
	else
		map->code = 0;
}

void	move(float *c, float *c1, int key)
{
	*c += key;
	*c1 += key;
}

void	stepping(float *x, float *y, float *x_size, float *y_size)
{
	*x += *x_size;
	*y += *y_size;
}
