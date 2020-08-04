/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:15:11 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/16 01:47:12 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_list	*create_elem(char *data)
{
	t_list		*elem;

	if (!(elem = (t_list*)ft_memalloc(sizeof(*elem))))
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

static void		list_pushback(t_list **begin_list, char *line)
{
	t_list		*head;

	if (!(*begin_list))
		*begin_list = create_elem(line);
	else
	{
		head = *begin_list;
		while (head->next)
			head = head->next;
		head->next = create_elem(line);
	}
}

static int		check_line(char *av, char *line, t_data *data)
{
	int			fd;
	int			i;

	i = -1;
	data->x_max = -42;
	data->y_max = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line))
	{
		list_pushback(&data->list, line);
		if (data->x_max == -42)
			data->x_max = ft_words_count(line, ' ');
		else if (data->x_max != ft_words_count(line, ' '))
			return (free_list(&data->list));
		data->y_max++;
	}
	i++;
	if ((close(fd)) == -1)
		return (-1);
	if (data->x_max == 0)
		return (-1);
	data->range = (LENGTH / (data->x_max * 4) + 1);
	data->range_x2 = data->range * 2;
	return (0);
}

static int		check_is_int(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] == '-' || str[i] == '+')
				&& !ft_isdigit(str[i + 1]))
			return (-1);
		if (!ft_isdigit(str[i]) && str[i] != ' '
				&& str[i] != '-' && str[i] != '+')
			return (-1);
	}
	return (0);
}

int				check_file(char *av, t_data *data)
{
	int			fd;
	int			ret;

	data->list = NULL;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (error());
	while ((ret = get_next_line(fd, &data->line)))
	{
		if (ret == 0 || ret == -1)
			return (error());
		if (check_is_int(data->line) == -1)
			return (free_str(data->line));
		free(data->line);
	}
	if (close(fd) == -1)
		return (error());
	if (check_line(av, data->line, data) == -1)
		return (-1);
	return (0);
}
