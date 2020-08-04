/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:45:08 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/06 22:35:52 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_words_count(const char *str, char c)
{
	int		count;
	int		word;
	int		i;

	count = 0;
	word = 0;
	i = 0;
	while (str[i])
	{
		if (word == 1 && str[i] == c)
			word = 0;
		if (word == 0 && !(str[i] == c))
		{
			word = 1;
			count++;
		}
		i++;
	}
	return (count);
}
