/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:33:52 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/08 14:19:34 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE	4096 * 4

typedef struct		s_lst
{
	int				file_d;
	char			*tmp;
	struct s_lst	*next;
}					t_lst;

/*
** -------------------------- get_next_line -----------------------------------
*/
int					get_next_line(int const fd, char **line);

#endif
