/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:20:23 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/13 20:52:58 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(char *av, t_data *d)
{
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, LENGTH, HEIGHT, &av[0]);
	d->picture.ptr = mlx_new_image(d->mlx_ptr, LENGTH, HEIGHT);
	d->picture.s = (int *)mlx_get_data_addr(d->picture.ptr,
											&d->picture.bits_per_pixel,
											&d->picture.size_line,
											&d->picture.endian);
	draw_map(d, d->width, d->height);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->picture.ptr, 0, 0);
}
