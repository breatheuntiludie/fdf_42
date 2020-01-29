/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:37:10 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/14 22:43:14 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp1;

	temp = *alst;
	temp1 = *alst;
	while (temp)
	{
		temp = temp1->next;
		del(temp1->content, temp1->content_size);
		free(temp1);
		temp1 = temp;
	}
	*alst = (void*)0;
}
