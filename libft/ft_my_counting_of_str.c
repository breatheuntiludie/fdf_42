/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_counting_of_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:57:59 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/13 23:17:46 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_my_counting_of_str(const char *s)
{
	int		length;
	int		k;

	k = 0;
	length = 0;
	if (s)
	{
		while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
			k++;
		length = ft_strlen(s) - 1;
		while (s[length] == ' ' || s[length] == '\n' || s[length] == '\t')
			length--;
		length = length - k + 1;
		if (length < 0)
			length = 0;
	}
	return (length);
}
