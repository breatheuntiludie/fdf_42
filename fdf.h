/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:24:53 by ggeri             #+#    #+#             */
/*   Updated: 2020/01/30 18:20:23 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct 	map_s
{
	int 	y;
	int 	x;
	int 	**z;
	int		scale;
	int		colour; //white - 0xffffff     red - 0xe80c0c

	void	*mlx_ptr;
	void	*win_ptr;
}				t_map;

void			draw_line(float x, float y, float x1, float y1, t_map *map);
void			read_map(char *file, t_map *map);
void			draw(t_map *map);

#endif
