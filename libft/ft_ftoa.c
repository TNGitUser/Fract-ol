/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:24:07 by lucmarti          #+#    #+#             */
/*   Updated: 2019/02/22 16:31:58 by lucmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long long	ft_rpart(long double n)
{
	return ((long long)n);
}

static int			ft_getlength(long long c)
{
	int i;

	if (c == 0)
		return (1);
	i = 0;
	if ((unsigned long long)c == (unsigned long long)MIN_LONG)
	{
		i = 1;
		c = c / 10;
	}
	c = ft_abs(c);
	while (c > 0)
	{
		++i;
		c = c / 10;
	}
	return (i);
}

static void	ft_rparta(char *str, long rpart, int *len)
{
	if (rpart == 0)
		str[(*len)--] = '0';
	else if (rpart < 0)
	{
		str[(*len)--] = ((rpart % 10) * -1) + '0';
		rpart = rpart / 10;
		str[0] = '-';
		rpart = ft_abs(rpart);
	}
	while (rpart > 0)
	{
		str[(*len)--] = (rpart % 10) + '0';
		rpart = rpart / 10;
	}
}

static void	ft_fparta(char *str, long double n, int *len, int precision)
{
	long double	fpart;
	long long	ftorpart;
	int			pr;
	int			last;

	pr = precision;
	fpart = (n - ft_rpart(n));
	fpart *= ft_power(10, (precision >= 10 ? 10 : precision));
	if (precision > 10)
		ft_fparta(str, fpart, len, precision - 10);
	if (precision < 10)
	{
		printf("{%.20Lf}\n", fpart);
		fpart *= 10;
		printf("{%.20Lf}\n", fpart);
		ftorpart = ft_rpart(fpart);
		printf("{%lld}\n", ftorpart);
		last = ftorpart % 10;
		ftorpart /= 10;
		if (last >= 5)
			ftorpart += 1;
	}
	else
		ftorpart = ft_rpart(fpart);
	int test = ft_getlength(ftorpart);
	if (ftorpart == 0)
		test--;
	if (ftorpart < 0)
		ftorpart = ft_abs(ftorpart);
	while (ftorpart > 0)
	{
		str[(*len)--] = (ftorpart % 10) + '0';
		ftorpart = ftorpart / 10;
	}
	while (test < (precision >= 10 ? 10 : precision % 10))
	{
		str[(*len)--] = '0';
		++test;
	}
}

char		*ft_ftoa(long double n, int pr)
{
	char	*str;
	int		len;
	long	rpart;

	rpart = ft_rpart(n);
	len = ft_getlength(rpart);
	len += (n < 0 ? 1 : 0);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 2 + pr))))
		return (NULL);
	len = len + 1 + pr;
	str[len--] = '\0';
	ft_fparta(str, n, &len, pr);
	str[len--] = '.';
	ft_rparta(str, rpart, &len);
	return (str);
}
