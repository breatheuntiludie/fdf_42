/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:25:40 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/14 20:41:08 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	loc;

	i = 0;
	loc = 0;
	if (s && f)
	{
		while (s[i])
		{
			loc = i;
			f(i, &s[loc]);
			i++;
		}
	}
}
