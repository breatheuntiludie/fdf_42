/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:08:26 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/03 20:03:17 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_map(t_map *map)
{
	map->key_x = 0;
	map->key_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	map->code = 0;
	map->rot_x = 0;
	map->angle_x = 0;
	map->rot_y = 0;
	map->angle_y = 0;
	map->rot_z = 0;
	map->angle_z = 0;
}

void	free_map(t_map *map)
{
	int i = 0;
	while (i != map->y)
		free(map->z[i]);
	free(map);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	if (argc != 2)
		return (0);
	map = (t_map*)malloc(sizeof(t_map));
	init_map(map);
	read_map(argv[1], map);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, SIZE, SIZE, "FDF");
	mlx_hook(map->win_ptr, 2, 0, press_key, map);
	mlx_key_hook(map->win_ptr, change_iso, map);
	map->key_y = SIZE / 2 - map->y * SCALE / 2;
	map->key_x = SIZE / 2 - map->x * SCALE / 2;
	draw(map);
	mlx_loop(map->mlx_ptr);
	ft_putnbr(34567);
	//free_map(map);
	return (0);
}
