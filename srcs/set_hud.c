/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:20:35 by luwargni          #+#    #+#             */
/*   Updated: 2019/05/31 19:38:40 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_hud(t_data *data)
{
	if (data->hud)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 0, WHITE,
									"Press a, w, s, d, for move the map");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 30, WHITE,
									"Press 'h' for HUD Close/Open");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 60, WHITE,
									"Press 'p' for projection");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 90, WHITE,
									"Press 'c' for color map");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 120, WHITE,
									"Arrow up/down = +/-");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 5, 150, WHITE,
									"Arrow left/right = +/-");
	}
}
