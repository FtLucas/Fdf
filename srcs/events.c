/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:20:48 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/16 01:48:15 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		limit(int key, t_data *data)
{
	if (key == UP || key == DOWN)
	{
		if (data->range != 0 && (size_t)data->range < data->range_x2)
			data->range += (key == DOWN ? -1 : 1);
		else if (key == UP && (size_t)data->range < data->range_x2)
			data->range += 1;
		else if (key == DOWN && data->range != 0)
			data->range += -1;
	}
	else if (key == LEFT || key == RIGHT)
	{
		if ((long double)data->n <= data->n_x2
			&& (long double)data->n >= data->n_x2 * -1)
			data->n += (key == LEFT ? 0.2 : -0.2);
		else if (key == RIGHT && (long double)data->n >= data->n_x2 * -1)
			data->n += -0.2;
		else if (key == LEFT && (long double)data->n <= data->n_x2)
			data->n += 0.2;
	}
}

int				close_button(t_data *data)
{
	t_list		*tmp;
	int			n;

	tmp = NULL;
	n = 0;
	while (data->list)
	{
		tmp = data->list;
		data->list = data->list->next;
		ft_strdel(&tmp->data);
		free(tmp);
	}
	while (n < data->y_max)
	{
		free(data->m[n]);
		n++;
	}
	free(data->m);
	mlx_destroy_image(data->mlx_ptr, data->picture.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int				triggered_key(int key, t_data *data)
{
	if (key == W || key == S)
		data->height += (key == W ? -10 : 10);
	else if (key == A || key == D)
		data->width += (key == A ? -10 : 10);
	else if (key == H)
		data->hud = (data->hud ? 0 : 1);
	else if (key == P)
		data->proj = (data->proj ? 0 : 1);
	else if (key == C)
		data->color = (data->color == BLUE ? RED : data->color >> 8);
	else if (key == RIGHT || key == LEFT)
		limit(key, data);
	else if (key == UP || key == DOWN)
		limit(key, data);
	else if (key == ESC)
		exit(0);
	ft_memset(data->picture.s, 0, data->picture.size_line * HEIGHT);
	draw_map(data, data->width, data->height);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
							data->picture.ptr, 0, 0);
	set_hud(data);
	return (0);
}
