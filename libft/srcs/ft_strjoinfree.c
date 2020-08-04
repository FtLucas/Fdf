/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luwargni <luwargni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 11:07:10 by luwargni          #+#    #+#             */
/*   Updated: 2019/06/06 22:35:13 by luwargni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char const *s1, char const *s2, int wfree)
{
	char	*str;

	if (wfree < 1 && wfree > 3)
		return (NULL);
	str = ft_strjoin(s1, s2);
	if (wfree == 1 || wfree == 3)
		free((char *)s1);
	if (wfree == 2 || wfree == 3)
		free((char *)s2);
	return (str);
}
