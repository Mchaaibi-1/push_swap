/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sort_easy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:37:13 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:48:39 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minindex(t_node **a, int min)
{
	int		indexzero;
	t_node	*h;

	indexzero = 0;
	h = *a;
	while (h)
	{
		if (h->index == min)
			return (indexzero);
		indexzero++;
		h = h->next;
	}
	return (indexzero);
}
