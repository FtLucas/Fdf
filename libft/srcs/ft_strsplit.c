/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 23:39:40 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/06 22:35:32 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wdsz(char const *s, int d, int c)
{
	size_t		i;

	i = 0;
	while (s[d] != c && s[d] != '\0')
	{
		i++;
		d++;
	}
	return (i);
}

static int		ft_wdnb(char const *str, char c)
{
	size_t		i;
	size_t		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			word++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		nb_w;
	char		**tab;

	i = 0;
	j = 0;
	if ((!(s)) || (!(tab = (char**)malloc(sizeof(char*)
		* (ft_wdnb(s, c) + 1)))))
		return (NULL);
	nb_w = ft_wdnb(s, c);
	while (nb_w--)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			tab[j] = ft_strsub(s, i, ft_wdsz(s, i, c));
			i = i + ft_wdsz(s, i, c);
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
