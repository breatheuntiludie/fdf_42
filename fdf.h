/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:24:53 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/02 17:23:45 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

# define SCALE 25

typedef struct	map_s
{
	int		y;
	int		x;
	int		**z;
	float	x_s;
	float	y_s;
	//int		scale;
	int		colour; //white - 0xffffff     red - 0xe80c0c
	int		key_x;
	int		key_y;
	void	*mlx_ptr;
	void	*win_ptr;
	int		min_z;
	int		max_z;

}				t_map;

void			scaling(float *x, float *y, float *x1, float *y1);
void			iso(float *x, float *y, int z);
void			move(float *c, float *c1, int key);
void			draw_line(float x1, float y1, t_map *map);
void			read_map(char *file, t_map *map);
void			draw(t_map *map);
int				press_key(int key, t_map *map);

#endif
