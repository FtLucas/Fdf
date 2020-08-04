/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:11:21 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/15 17:19:50 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_data	data;

	if (!(ac == 2))
	{
		ft_putendl("usage : ./fdf source_file");
		return (-1);
	}
	else if (check_file(av[1], &data) == -1)
		return (-1);
	else if (set_map(&data) == -1)
		return (-1);
	else
		init_mlx(av[1], &data);
	mlx_hook(data.win_ptr, 2, 0, triggered_key, &data);
	mlx_hook(data.win_ptr, 17, 0, close_button, &data);
	set_hud(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
