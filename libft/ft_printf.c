/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:32:51 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:52:10 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_put_string(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_put_nbr(int nb)
{
	int		l;
	char	*n;

	l = 0;
	n = ft_itoa(nb);
	l = ft_put_string(n);
	free(n);
	return (l);
}

int	ft_printf(const char *s, ...)
{
	int		l;
	int		i;
	va_list	lst;

	l = 0;
	i = -1;
	va_start(lst, s);
	while (s && s[++i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 's')
				l = l + ft_put_string(va_arg(lst, char *));
			if (s[i + 1] == 'd')
				l = l + ft_put_nbr(va_arg(lst, int));
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			l++;
		}
	}
	va_end(lst);
	return (l);
}
