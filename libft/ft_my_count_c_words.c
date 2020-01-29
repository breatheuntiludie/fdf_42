/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_count_c_words.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:31:33 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/13 23:54:54 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_my_count_c_words(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (s)
	{
		while (*s != '\0')
		{
			i = 0;
			while (*s == c)
				s++;
			while (*s != c && *s != '\0')
			{
				i = 1;
				s++;
			}
			if (i == 1)
				count++;
		}
	}
	return (count);
}
