/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:08:26 by ggeri             #+#    #+#             */
/*   Updated: 2020/01/29 17:14:36 by ggeri            ###   ########.fr       */
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
	//readinf of file from Sasha
	//map->mlx_ptr = mlx_init();
	return (0);
}
