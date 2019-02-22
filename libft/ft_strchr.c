/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:01:20 by lucmarti          #+#    #+#             */
/*   Updated: 2018/11/08 11:07:33 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*cs;

	cs = (char *)s;
	while (*cs != '\0')
	{
		if (*cs == c)
			return (cs);
		++cs;
	}
	if (c == '\0' && *cs == '\0')
		return (cs);
	return (NULL);
}
