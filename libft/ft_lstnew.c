/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:27:39 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/16 17:55:10 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	temp = (t_list*)malloc(sizeof(t_list));
	if (!temp)
	{
		free(temp);
		return ((void*)0);
	}
	if (!content)
	{
		temp->content = (void*)0;
		temp->content_size = 0;
	}
	else
	{
		temp->content = (void*)malloc(content_size);
		ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	temp->next = (void*)0;
	return (temp);
}
