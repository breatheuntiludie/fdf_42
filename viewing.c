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

void	iso(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(30 * 3.14 / 180);
	*y = (*x + *y) * sin(30 * 3.14 / 180) - z;
}

void	move(float *c, float *c1, int key)
{
	*c += key;
	*c1 += key;
}
