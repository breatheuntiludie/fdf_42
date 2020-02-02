/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:08:26 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/02 20:32:21 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	int i;
	int j;

	if (argc != 2)
		return (0);

	map = (t_map*)malloc(sizeof(t_map));
	map->code = 0;
	map->key_x = 0;
	map->key_y = 0;
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
	map->win_ptr = mlx_new_window(map->mlx_ptr, SIZE, SIZE, "FDF");
	mlx_hook(map->win_ptr, 2, 0, press_key, map);
	mlx_key_hook(map->win_ptr, change_iso, map);

	draw(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
