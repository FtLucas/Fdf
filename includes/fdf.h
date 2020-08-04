/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:11:21 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/16 01:47:15 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define W					13
# define A					0
# define S					1
# define D					2
# define H					4
# define P					35
# define C					8
# define ESC				53
# define UP					126
# define DOWN				125
# define LEFT				123
# define RIGHT				124

# define LENGTH				1920
# define HEIGHT				1280
# define MENU_LENGTH_RIGHT	1420
# define MENU_LENGTH_LEFT	500

# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E
# define WHITE				0xFFFFFF
# define BLUE				0x0000FF
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BROWN				0x4d3300

typedef struct		s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_picture
{
	void			*ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*s;
}					t_picture;

typedef struct		s_point
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
	int				x;
	int				x1;
	int				y;
	int				y1;
}					t_point;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*line;
	int				x_max;
	int				y_max;
	int				width;
	int				height;
	size_t			range_x2;
	int				range;
	int				proj;
	double			n;
	long double		n_x2;
	int				color;
	int				**m;
	int				hud;
	t_list			*list;
	t_picture		picture;
	t_point			p;
}					t_data;

/*
** ------------------------------- check_file ----------------------------------
*/
int					check_file(char *av, t_data *data);

/*
** ------------------------------- draw_map ------------------------------------
*/
void				draw_map(t_data *data, int l, int h);

/*
** ------------------------------- events --------------------------------------
*/
int					close_button(t_data *data);
int					triggered_key(int key, t_data *data);

/*
** ------------------------------- free_list -----------------------------------
*/
int					free_list(t_list **list);
int					free_str(char *str);
int					error(void);

/*
** ------------------------------- init_mlx ------------------------------------
*/
void				init_mlx(char *av, t_data *d);

/*
** ------------------------------- ligne ---------------------------------------
*/
void				ligne(t_data *data, int l, int h, int z);

/*
** ------------------------------- manage_point --------------------------------
*/
int					free_point(t_point **p);
int					set_point(t_point **p);

/*
** ------------------------------- set_hud -------------------------------------
*/
void				set_hud(t_data *data);

/*
** ------------------------------- set_map -------------------------------------
*/
int					set_map(t_data *data);

#endif
