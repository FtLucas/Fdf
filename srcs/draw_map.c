/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:37:17 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/12 19:31:54 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_background(t_data *data)
{
	int			i;
	int			*image;

	i = 0;
	image = (int *)(data->picture.s);
	while (i < HEIGHT * LENGTH)
	{
		if (i % LENGTH < MENU_LENGTH_LEFT)
			image[i] = MENU_BACKGROUND;
		else if (i % LENGTH > MENU_LENGTH_RIGHT)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

static void		draw_point(t_data *d, t_point i)
{
	int			gap;
	int			ox;
	int			y;
	int			oy;
	int			z;

	gap = d->range;
	ox = i.x - d->x_max / 2;
	y = i.x1 - d->x_max / 2;
	oy = i.y - d->y_max / 2;
	z = i.y1 - d->y_max / 2;
	if (d->proj)
	{
		d->p.x = ((ox - oy) * cos(M_PI / 6)) * gap;
		d->p.y = (-(d->m[i.y][i.x] * d->n) + (ox + oy) * sin(M_PI / 6)) * gap;
		d->p.x1 = ((y - z) * cos(M_PI / 6)) * gap;
		d->p.y1 = ((-d->m[i.y1][i.x1] * d->n) + (y + z) * sin(M_PI / 6)) * gap;
	}
	else
	{
		d->p.x = ((ox - d->m[i.y][i.x] * d->n) * cos(M_PI / 4)) * gap;
		d->p.y = ((oy - d->m[i.y][i.x] * d->n) * sin(M_PI / 4)) * gap;
		d->p.x1 = ((y - d->m[i.y1][i.x1] * d->n) * cos(M_PI / 4)) * gap;
		d->p.y1 = ((z - d->m[i.y1][i.x1] * d->n) * sin(M_PI / 4)) * gap;
	}
}

void			draw_map(t_data *d, int l, int h)
{
	t_point		i;

	draw_background(d);
	i.y = -1;
	while (++(i.y) < d->y_max)
	{
		i.x = -1;
		while (++(i.x) < d->x_max)
		{
			if (i.x + 1 < d->x_max)
			{
				i.x1 = i.x + 1;
				i.y1 = i.y;
				draw_point(d, i);
				ligne(d, l, h, (d->m[i.y][i.x] || d->m[i.y][i.x + 1]) ? 1 : 0);
			}
			if (i.y + 1 < d->y_max)
			{
				i.x1 = i.x;
				i.y1 = i.y + 1;
				draw_point(d, i);
				ligne(d, l, h, (d->m[i.y][i.x] || d->m[i.y + 1][i.x]) ? 1 : 0);
			}
		}
	}
}
