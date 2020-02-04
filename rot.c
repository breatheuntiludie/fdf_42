/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:38:20 by icanker           #+#    #+#             */
/*   Updated: 2020/02/04 17:38:23 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(float *x, float *y, int z, t_map *map)
{
	int		t;

	if (map->rot_x == 1)
	{
		*x = *x;
		t = *y;
		*y = *y * cos(map->angle_x * 0.0174) + z * sin(map->angle_x * 0.0174);
		z = 0 - t * sin(map->angle_x * 0.0174) + z * cos(map->angle_x * 0.0174);
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
		*x = *x * cos(map->angle_y * 0.0174) + z * sin(map->angle_y * 0.0174);
		*y = *y;
		z = 0 - t * sin(map->angle_y * 0.0174) + z * cos(map->angle_y * 0.0174);
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
		*x = *x * cos(map->angle_z * 0.0174) - *y * sin(map->angle_z * 0.0174);
		*y = *y * cos(map->angle_z * 0.0174) + t * sin(map->angle_z * 0.0174);
		z = z;
	}
	else
		map->rot_z = 0;
}
