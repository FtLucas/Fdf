/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 00:53:41 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/15 19:24:15 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		limit(t_data *data, char **split, int i, int j)
{
	if (ft_atoi(split[i]) >= 5000)
		data->m[j][i] = 5000;
	else if (ft_atoi(split[i]) <= -5000)
		data->m[j][i] = -5000;
	else
		data->m[j][i] = ft_atoi(split[i]);
}

static int		fill_map(t_data *data)
{
	t_list		*tmp;
	char		**split;
	int			i;
	int			j;

	j = 0;
	tmp = data->list;
	while (tmp)
	{
		i = -1;
		if ((*(split = ft_strsplit(tmp->data, ' '))) == NULL)
			return (-1);
		while (++i < data->x_max)
			limit(data, split, i, j);
		ft_freetab((void***)&split);
		j++;
		tmp = tmp->next;
	}
	return (0);
}

int				set_map(t_data *data)
{
	int			i;
	int			**tab;

	if (!(tab = (int**)malloc(sizeof(int*) * data->y_max)))
		return (free_list(&data->list));
	data->height = HEIGHT / 2;
	data->width = LENGTH / 2;
	data->color = RED;
	data->proj = 1;
	data->hud = 1;
	data->n = 1.0;
	data->n_x2 = data->n * 2;
	i = -1;
	while (++i < data->y_max)
	{
		if (!(tab[i] = (int*)malloc(sizeof(int) * data->x_max)))
		{
			ft_freetab((void***)&tab);
			return (free_list(&data->list));
		}
	}
	data->m = tab;
	if (fill_map(data) == -1)
		return (-1);
	return (0);
}
