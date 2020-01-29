/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:11:30 by ggeri             #+#    #+#             */
/*   Updated: 2019/10/10 20:46:47 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*find_create(const int fd, t_list **link)
{
	t_list	*temp;

	if (!*link)
	{
		*link = (t_list*)malloc(sizeof(t_list));
		(*link)->content = "";
		(*link)->content_size = (size_t)fd;
		(*link)->next = NULL;
	}
	temp = *link;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		if (temp->next != NULL)
			temp = temp->next;
		else
			break ;
	}
	temp->next = (t_list*)malloc(sizeof(t_list));
	temp = temp->next;
	temp->content = "";
	temp->content_size = (size_t)fd;
	temp->next = NULL;
	return (temp);
}

static int		parsing(const int fd, char **line, t_list *current)
{
	int		answer;
	char	temp[BUFF_SIZE + 1];
	char	*helper;

	ft_bzero(temp, BUFF_SIZE + 1);
	while ((answer = read(fd, temp, BUFF_SIZE)) > 0 && \
			(helper = current->content))
	{
		current->content = ft_strjoin(helper, temp);
		ft_bzero(temp, BUFF_SIZE);
		if (ft_strlen(helper) != 0)
			free(helper);
		if (ft_strchr(current->content, '\n'))
			break ;
	}
	if (ft_strchr(current->content, '\n') && (answer = 1))
	{
		*line = ft_my_malloc_c_word(current->content, '\n');
		helper = current->content;
		current->content = ft_strdup(ft_strchr(helper, '\n') + 1);
		free(helper);
	}
	else if (ft_strlen(current->content) != 0 && (answer = 2))
		*line = ft_strdup(current->content);
	return (answer);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*link;
	int				ret;
	t_list			*current;

	if (!line || fd < 0 || BUFF_SIZE < 0 || (read(fd, NULL, 0) == -1))
		return (-1);
	current = find_create(fd, &link);
	ret = parsing(fd, line, current);
	if (ft_strcmp(*line, current->content) == 0 && \
			ft_strchr(current->content, '\n') == NULL && ret == 2)
	{
		ret = 1;
		if (ft_strlen(current->content) > 0)
			free(current->content);
		current->content = "";
	}
	return (ret);
}
