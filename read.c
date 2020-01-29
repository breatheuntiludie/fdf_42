/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icanker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:08:06 by icanker           #+#    #+#             */
/*   Updated: 2020/01/29 16:08:09 by icanker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_height(char *file)
{
    char    *line;
    int     fd;
    int     y;

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

int get_width(char *file)
{
    int     x;
    int     fd;
    char    *line;
    char    **loc;

    fd = open(file, O_RDONLY, 0);
    get_next_line(fd, &line);
    
    x = 0;
    loc = ft_strsplit(line, ' ');
    
    while (loc[x])
        x++;
    close(fd);
    
    return (x);
}

void    fill_z(int *line_z, char *line)
{
    char    **nbrs;
    int     i;


    i = 0;
    nbrs = ft_strsplit(line, ' ');
    while (nbrs[i])
    {
        line_z[i] = ft_atoi(nbrs[i]);
        free(nbrs[i]);
        i++;
    }
    free(nbrs);
}

void read_map(char *file, t_map *map)
{
    int     fd;
    char    *line;
    int     i;

    map->x = get_width(file);
    ft_putnbr(map ->x);
	ft_putchar('\n');
    map->y = get_height(file);
    ft_putnbr(map ->y);
	ft_putchar('\n');
    map->z = (int **)malloc(sizeof(int *) * (map->y + 1));
    i = 0;
    while (i != map->y)
    {
        map->z[i++] = (int *)malloc(sizeof(int) * (map->x + 1));
    }
    fd = open(file, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_z(map->z[i], line);
        free(line);
        i++;
    }
    close(fd);
    map->z[i] = NULL;
}
