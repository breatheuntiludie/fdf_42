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

void	rot_x(float *x, float *y, int z, t_map *map)
{
	int		t;

	if (map->rot_x == 1)
	{
		*x = *x;
		t = *y;
		*y = *y * cos(map->angle_x * 3.14/180) + z * sin(map->angle_x * 3.14/180);
		z = 0 - t * sin(map->angle_x * 3.14/180) + z * cos(map->angle_x * 3.14/180);
	}
	else
		map->rot_x = 0;
}

void	rot_y(float *x, float *y, int z, t_map *map)
{
	int		t;

	if (map->rot_y == 1)
	{
		t = *x;
		*x = *x * cos(map->angle_y * 3.14 / 180) + z * sin(map->angle_y * 3.14 / 180);
		*y = *y;
		z = 0 - t * sin(map->angle_y * 3.14/180) + z * cos(map->angle_y * 3.14/180);
	}
	else
		map->rot_y = 0;
}

void	rot_z(float *x, float *y, int z, t_map *map)
{
	int		t;

	if (map->rot_z == 1)
	{
		t = *x;
		*x = *x * cos(map->angle_z * 3.14 / 180) - *y * sin(map->angle_z * 3.14/180);
		*y = *y * cos(map->angle_z * 3.14 / 180) + t * sin(map->angle_z * 3.14 / 180);
		z = z;
	}
	else
		map->rot_z = 0;
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
