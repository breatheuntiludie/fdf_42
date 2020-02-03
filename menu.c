/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:52:35 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/03 19:55:40 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_menu(t_map *map)
{
	int		c[9];
	// int		a;
	// int		b;
	// int		d;
	// int		e;
	// int		f;
	// int		g;
	// int		h;
	// int		i;

	c[0] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0xe80c0c, \
	"MENU:");
	c[1] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 25, 0xe80c0c, \
	"1) '+/-' - change map from plane to isometric");
	c[2] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 40, 0xe80c0c, \
	"2) 'arrows' - move left, right, up, down");
	c[3] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 55, 0xe80c0c, \
	"3) 'TAB' - to centre map");
	c[4] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 70, 0xe80c0c, \
	"4) 'X' - X-Axis rotation ");
	c[5] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 85, 0xe80c0c, \
	"5) 'Y' - Y-Axis rotation ");
	c[6] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 100, 0xe80c0c, \
	"6) 'Z' - Z-Axis rotation ");
	c[7] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 115, 0xe80c0c, \
	"7) 'R' - Reload picture to plane moment");
	c[8] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 130, 0xe80c0c, \
	"8) 'ESC' - exit and close");

	// void	*menu;
	// void	*menu_1;
	// int		check;
	// int		absciss = 500;
	// int		ordinat = 700;

	// menu = mlx_new_image(map->mlx_ptr, absciss, ordinat);
	// char *line;
	// line = ft_strjoin("", "MENU");
	// // check = mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, menu, 0, 0);
	// // menu_1 = mlx_xpm_to_image(map->mlx_ptr, &line, &absciss, &ordinat);
	// char *filename = "20190904_182125.jpg";
	// menu_1 = mlx_xpm_file_to_image(map->mlx_ptr, filename, &absciss, &ordinat);
	// check = mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, menu, 10, 10);
}
