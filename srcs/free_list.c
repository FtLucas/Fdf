/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:11:45 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/15 17:11:08 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			error(void)
{
	ft_putendl("\\ERROR/");
	return (-1);
}

int			free_str(char *str)
{
	free(str);
	ft_putendl("\\ERROR/");
	return (-1);
}

int			free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->data);
		(*list)->data = NULL;
		free(*list);
		*list = tmp;
	}
	ft_putendl("\\ERROR/");
	return (-1);
}
