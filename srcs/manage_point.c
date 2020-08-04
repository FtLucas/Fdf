/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:50:52 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/01 20:14:23 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*create_point(void)
{
	t_point		*p;

	if (!(p = malloc(sizeof(*p))))
		return (NULL);
	p->dx = 0;
	p->sx = 0;
	p->dy = 0;
	p->sy = 0;
	p->err = 0;
	p->e2 = 0;
	p->x = 0;
	p->x1 = 0;
	p->y = 0;
	p->y1 = 0;
	return (p);
}

int				free_point(t_point **p)
{
	if (p != NULL && *p != NULL)
	{
		free((*p));
		(*p) = NULL;
		return (1);
	}
	return (0);
}

int				set_point(t_point **p)
{
	if (p != NULL)
	{
		if ((*p = create_point()) != NULL)
			return (1);
		return (-1);
	}
	return (0);
}
