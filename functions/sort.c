/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:32:39 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:50:29 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	issorted(t_node **stk)
{
	t_node	*t;

	t = *stk;
	while (t && t->next)
	{
		if (t->data > t->next->data)
			return (0);
		t = t->next;
	}
	return (1);
}

void	stack_free(t_node **stk)
{
	t_node	*h;
	t_node	*t;

	h = *stk;
	while (h)
	{
		t = h;
		h = h->next;
		free(t);
	}
	free(stk);
}

int	list_length(t_node *h)
{
	t_node	*t;
	int		lenght;

	t = h;
	lenght = 1;
	if (!t)
		return (0);
	while (t->next)
	{
		lenght++;
		t = t->next;
	}
	return (lenght);
}
