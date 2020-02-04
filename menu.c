/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:52:35 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/03 20:03:45 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	place_menu(t_map *map)
{
	int	c[9];

	c[0] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0xe80c0c, \
	"MENU:");
	c[1] = mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 25, 0xe80c0c, \
	"1) '+' - change map from plane to isometric");
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
}
