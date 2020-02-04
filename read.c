/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:08:06 by icanker           #+#    #+#             */
/*   Updated: 2020/02/03 20:03:35 by ggeri            ###   ########.fr       */
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

int		get_height(char *file)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		y++;
		free(line);
	}
	close(fd);
	return (y);
}

int		get_width(char *file)
{
	int		x;
	int		fd;
	char	*line;
	char	**loc;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	x = 0;
	loc = ft_strsplit(line, ' ');
	while (loc[x])
		x++;
	close(fd);
	return (x);
}

void	fill_z(int *line_z, char *line, int *min_z, int *max_z)
{
	char	**nbrs;
	int		i;

	i = 0;
	nbrs = ft_strsplit(line, ' ');
	while (nbrs[i])
	{
		line_z[i] = ft_atoi(nbrs[i]);
		*max_z = (line_z[i] > *max_z) ? line_z[i] : *max_z;
		*min_z = (line_z[i] > *min_z) ? *min_z : line_z[i];
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

void	read_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	map->x = get_width(file);
	map->y = get_height(file);
	map->z = (int **)malloc(sizeof(int *) * (map->y + 1));
	i = 0;
	while (i != map->y)
		map->z[i++] = (int *)malloc(sizeof(int) * (map->x + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_z(map->z[i], line, &(map->min_z), &(map->max_z));
		free(line);
		i++;
	}
	close(fd);
	map->z[i] = NULL;
}
