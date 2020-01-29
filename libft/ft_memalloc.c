/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:43:03 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/11 20:59:26 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*temp;

	i = 0;
	temp = (void*)malloc(size);
	if (!temp)
		return (0);
	while (i < size)
	{
		((char*)temp)[i] = 0;
		i++;
	}
	return (temp);
}
