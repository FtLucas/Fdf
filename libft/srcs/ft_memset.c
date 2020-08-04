/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 02:48:22 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/06 22:34:22 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	char	*m;
	size_t	i;

	m = (char *)s;
	i = 0;
	while (i < n)
	{
		m[i] = (char)c;
		i++;
	}
	return (s);
}
