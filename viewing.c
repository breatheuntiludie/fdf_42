/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:20:12 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/02 17:22:38 by ggeri            ###   ########.fr       */
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
	int	t;

	if (map->code == 1)
	{
		t = *x;
		*x = (*x - *y) * cos(30 * 3.14 / 180);
		*y = (t + *y) * sin(30 * 3.14 / 180) - z;
	}
	else
	{
		map->code = 0;
	}
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