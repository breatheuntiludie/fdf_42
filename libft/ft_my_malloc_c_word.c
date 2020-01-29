/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_malloc_c_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:29:47 by ggeri             #+#    #+#             */
/*   Updated: 2019/09/13 23:48:00 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_my_malloc_c_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = (void*)0;
	if (s)
	{
		while (s[i] && s[i] != c)
			i++;
		word = (char*)malloc(sizeof(char) * (i + 1));
		i = 0;
		while (s[i] && s[i] != c)
		{
			word[i] = s[i];
			i++;
		}
		word[i] = '\0';
	}
	return (word);
}
