/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:39:09 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/11 21:50:20 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = (char*)malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (0);
	while (i < size + 1)
	{
		temp[i] = '\0';
		i++;
	}
	return (temp);
}
