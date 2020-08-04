/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:22:08 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/09 17:26:59 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		in_window(t_point point, int l, int h)
{
	if ((point.x + l < LENGTH && point.x + l >= 0)
			&& (point.y + h < HEIGHT && point.y + h >= 0))
		return (1);
	return (0);
}

static int		get_color(int flag, t_data *data)
{
	if (flag == 1)
		return (data->color);
	return (BROWN);
}

static int		ligne_inner(t_data *data, t_point **p, int l, int h)
{
	if (set_point(p) != 1)
		return (0);
	(*p)->dx = abs((data->p.x1 + l) - (data->p.x + l));
	(*p)->sx = data->p.x < data->p.x1 ? 1 : -1;
	(*p)->dy = abs((data->p.y1 + h) - (data->p.y + h));
	(*p)->sy = data->p.y < data->p.y1 ? 1 : -1;
	(*p)->err = ((*p)->dx > (*p)->dy ? (*p)->dx : -(*p)->dy) / 2;
	return (1);
}

void			ligne(t_data *data, int l, int h, int z)
{
	t_point		*point;

	if (ligne_inner(data, &point, l, h) != 1)
		return ;
	while (1)
	{
		if (in_window(data->p, l, h))
			data->picture.s[data->p.x + l
				+ ((data->p.y + h) * LENGTH)] = get_color(z, data);
		if (data->p.x == data->p.x1 && data->p.y == data->p.y1)
			break ;
		point->e2 = point->err;
		if (point->e2 > -point->dx)
		{
			point->err -= point->dy;
			data->p.x += point->sx;
		}
		if (point->e2 < point->dy)
		{
			point->err += point->dx;
			data->p.y += point->sy;
		}
	}
	free_point(&point);
}
