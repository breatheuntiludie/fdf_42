/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:23:49 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/11 18:56:10 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (haystack[i] == '\0' && needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i + k] == needle[j] && needle[j])
		{
			k++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char*)haystack + i);
		j = 0;
		k = 0;
		i++;
	}
	return (0);
}
