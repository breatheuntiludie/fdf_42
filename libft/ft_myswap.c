/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:00:45 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/26 20:51:37 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_myswap(char *s)
{
	size_t	i;
	char	local;
	size_t	size;

	i = 0;
	size = ft_strlen(s) - 1;
	if (s)
	{
		while (i < size)
		{
			local = s[size];
			s[size] = s[i];
			s[i] = local;
			size--;
			i++;
		}
	}
	return (s);
}
