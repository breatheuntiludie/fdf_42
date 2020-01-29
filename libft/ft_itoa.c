/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:54:27 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/12 23:30:57 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*temp;
	int		size;

	size = ft_mylengthofnum(n) + 1;
	temp = malloc(sizeof(char) * size);
	if (!temp)
		return ((void*)0);
	temp[size - 1] = '\0';
	ft_fillmynbr(temp, n, size - 1);
	return (temp);
}
