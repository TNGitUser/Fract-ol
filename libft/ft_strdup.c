/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:24:59 by lucmarti          #+#    #+#             */
/*   Updated: 2018/11/21 10:17:33 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

char		*ft_strdup(const char *src)
{
	int		l;
	int		i;
	char	*dup;

	l = ft_len(src);
	dup = NULL;
	i = 0;
	if (!(dup = (char *)malloc(sizeof(*dup) * (l + 1))))
		return (NULL);
	dup[l] = '\0';
	while (*src != '\0')
	{
		dup[i] = *src;
		++src;
		++i;
	}
	return (dup ? dup : NULL);
}
