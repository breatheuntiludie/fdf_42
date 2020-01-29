/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 23:02:50 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/02 17:52:27 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new_t;
	t_list	*local;
	t_list	*res;

	temp = lst;
	local = f(temp);
	res = ft_lstnew(local->content, local->content_size);
	if (!lst || res == (void*)0 || !f)
		return ((void*)0);
	new_t = res;
	while (temp->next)
	{
		temp = temp->next;
		local = f(temp);
		res->next = ft_lstnew(local->content, local->content_size);
		if (res->next == (void*)0)
		{
			ft_mydltlst(new_t);
			return ((void*)0);
		}
		res = res->next;
	}
	return (new_t);
}
