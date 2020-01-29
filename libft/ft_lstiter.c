/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:52:23 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/02 17:51:49 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *temp;
	t_list *temp1;

	temp = lst;
	temp1 = temp;
	if (lst && f)
	{
		while (temp)
		{
			temp1 = temp->next;
			f(temp);
			temp = temp1;
		}
	}
}
