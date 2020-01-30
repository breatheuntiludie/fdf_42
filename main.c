/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:08:26 by ggeri             #+#    #+#             */
/*   Updated: 2020/01/30 20:43:02 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	int i;
	int j;

	map = (t_map*)malloc(sizeof(t_map));
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
	//drawing
	//hotkeys
	mlx_key_hook(map->win_ptr, press_key, map);
	//mlx_loop_hook(map->mlx_ptr, press_key_0, map);
	draw(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
