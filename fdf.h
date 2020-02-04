/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:24:53 by ggeri             #+#    #+#             */
/*   Updated: 2020/02/03 19:47:52 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>

# define SCALE 30
# define MOVE 15
# define PROJECTION 1
# define SIZE 999

typedef struct	s_map
{
	int		y;
	int		x;
	int		**z;
	float	x_s;
	float	y_s;
	int		colour; //white - 0xffffff     red - 0xe80c0c
	int		key_x;
	int		key_y;
	void	*mlx_ptr;
	void	*win_ptr;
	int		min_z;
	int		max_z;
	int		code;
	int		rot_x;
	int		angle_x;
	int		rot_y;
	int		angle_y;
	int		rot_z;
	int		angle_z;
}				t_map;

typedef struct	s_dpoint
{
	float		y;
	float		x;
	float		y1;
	float		x1;
	float		z;
	float		z1;
}				t_dpoint;

void			place_menu(t_map *map);
void			scaling(float *x, float *y, float *x1, float *y1);
void			rot_x(float *x, float *y, int z, t_map *map);
void			rot_y(float *x, float *y, int z, t_map *map);
void			rot_z(float *x, float *y, int z, t_map *map);
void			iso(float *x, float *y, int z, t_map *map);
void			move(float *c, float *c1, int key);
void			stepping(float *x, float *y, float *x_size, float *y_size);
void			draw_line(float x1, float y1, t_map *map);
void			read_map(char *file, t_map *map);
void			draw(t_map *map);
int				press_key(int key, t_map *map);
int				change_iso(int key, t_map *map);
int				mouse(int key, t_map *map);
int				make_color(float z, t_map *map);
// int				press_mouse(int button, int x, int y, t_map *map);
// int				release_mouse(int button, int x, int y, t_map *map);
// int				move_mose(int x, int y, t_map *map);
#endif
