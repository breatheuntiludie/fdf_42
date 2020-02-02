/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:08:26 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/02 14:44:56 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	find_max(float x_size, float y_size)
{
	if (x_size > y_size)
		return (x_size);
	else
		return (y_size);
}

static float	find_mod(float x_size)
{
	if (x_size < 0)
		x_size *= -1;
	else
		x_size *= 1;
	return (x_size);
}

static void		local(float *x_size, float *y_size)
{
	int max;

	max = find_max(find_mod(*x_size), find_mod(*y_size));
	*x_size /= max;
	*y_size /= max;
}

int	make_color(int z, t_map *map)
{
	int h;
	int p;

	h = (map->max_z - map->min_z) / 16;//16^5
	p = (h) ? z/h : z;
	return (0xff6600 - z * 1048576);
}



void	draw_line(float x1, float y1, t_map *map)
{
	float	x_size;
	float	y_size;
	int		z;
	int		z1;
	float	x;
	float	y;

	x = map->x_s;
	y = map->y_s;
	z = map->z[(int)y][(int)x];
	z1 = map->z[(int)y1][(int)x1];
	scaling(&x, &y, &x1, &y1);
	
	//map->colour = (z) ? 0xff6600 : 0xffffff;
	iso(&x, &y, z);
	iso(&x1, &y1, z1);
	move(&x, &x1, map->key_x);
	move(&y, &y1, map->key_y);
	x_size = x1 - x;
	y_size = y1 - y;
	local(&x_size, &y_size);
	while ((int)(x - x1) || (int)(y - y1))
	{
		z = (x1 - x) ? find_mod(z1 - z)/(x1 - x) : find_mod(z1 - z)/(y1 - y);
		map->colour = make_color(z, map);
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, map->colour);
		x += x_size;
		y += y_size;
	}
}


void	draw(t_map *map)
{
	map->y_s = 0;
	while (map->y_s < map->y)
	{
		map->x_s = 0;
		while (map->x_s < map->x)
		{
			if (map->x_s < map->x - 1)
				draw_line(map->x_s + 1, map->y_s, map);
			if (map->y_s < map->y - 1)
				draw_line(map->x_s, map->y_s + 1, map);
			(map->x_s)++;
		}
		(map->y_s)++;
	}
}

int		main(int argc, char **argv)
{
	t_map	*map;
	int i;
	int j;

	if (argc != 2)
		return (0);

	map = (t_map*)malloc(sizeof(t_map));
	map->key_x = 0;
	map->key_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	read_map(argv[1], map);

	i = 0;
	while (i != map->y)
	{
		j = 0;
		while(j != map->x)
		{
			ft_putnbr((map->z)[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;

	}
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");

	mlx_hook(map->win_ptr, 2, 0, press_key, map);
	//mlx_key_hook(map->win_ptr, exit_map, map);
	draw(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
