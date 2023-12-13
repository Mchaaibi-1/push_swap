/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 05:07:36 by mchaaibi          #+#    #+#             */
/*   Updated: 2022/11/20 16:18:09 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *d, const char *s, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	dst = (char *)d;
	if (!s[i] || dst == s)
		return ((char *)dst);
	if (!d && !len)
		return (NULL);
	while (dst[i] && len > i)
	{
		j = 0;
		while (s[j] && i + j < len && dst[i + j] == s[j])
		{
			if (s[j + 1] == '\0')
				return (dst + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
