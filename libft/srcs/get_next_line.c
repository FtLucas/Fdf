/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:18:45 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/06 22:36:32 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_lst		*ft_check_alloc(t_lst **head, const int fd)
{
	t_lst			*temp;

	if (!(*head))
	{
		if (!((*head) = ft_memalloc(sizeof(t_lst))))
			return (NULL);
		(*head)->file_d = fd;
	}
	temp = (*head);
	while (temp->next != NULL && temp->file_d != fd)
		temp = temp->next;
	if (temp->next == NULL && temp->file_d != fd)
	{
		if (!(temp->next = ft_memalloc(sizeof(t_lst))))
			return (NULL);
		temp->next->file_d = fd;
		temp = temp->next;
	}
	return (temp);
}

static int			ft_malloc_dup(char **str, int i, char **line, char **tmp)
{
	if (!(*line = ft_strndup((*str), i)))
		return (-1);
	if (!(*tmp = ft_strdup(&(*str)[i + 1])))
		return (-1);
	return (0);
}

static int			ft_new_line(char **str, char **line, int ret)
{
	char			*pos;
	char			*tmp;
	size_t			i;

	if (*str == NULL && ret == 0)
		return (0);
	pos = ft_strchr((*str), '\n');
	if (ret == 0 && pos == NULL && *str)
	{
		if (ft_strlen(*str) == 0)
			return (0);
		if (!(*line = ft_strdup((*str))))
			return (-1);
		ft_strdel(str);
		return (1);
	}
	i = (pos - *str);
	if (ft_malloc_dup(str, i, line, &tmp) == -1)
		return (-1);
	free((*str));
	(*str) = tmp;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_lst	*head;
	t_lst			*lst;

	if (fd < 0 || read(fd, buf, 0) || !(lst = ft_check_alloc(&head, fd)))
		return (-1);
	while ((ret = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (lst->tmp == NULL)
			lst->tmp = ft_strdup(buf);
		else
			lst->tmp = ft_strjoinfree(lst->tmp, buf, 1);
		if (ft_strchr(lst->tmp, '\n'))
			return (ft_new_line(&(lst->tmp), line, ret));
	}
	return (ft_new_line(&(lst->tmp), line, ret));
}
