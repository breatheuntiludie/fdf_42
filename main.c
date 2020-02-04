/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:08:26 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/04 20:20:01 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (0);
}
