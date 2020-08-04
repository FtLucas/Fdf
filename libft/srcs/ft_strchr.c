/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 05:09:53 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/06 22:34:37 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != c)
	{
		if (!(s[i]))
			return (NULL);
		i++;
		count++;
	}
	return ((char *)s + count);
}
