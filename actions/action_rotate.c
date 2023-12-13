/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:29:08 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:48:48 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_revrotate(t_node **stk)
{
	t_node	*t;
	t_node	*last;

	if (list_length(*stk) <= 1)
		return (0);
	t = *stk;
	last = lastlist(*stk);
	*stk = last;
	last->next = t;
	while (t->next)
	{
		if (t->next == last)
			t->next = 0;
		else
			t = t->next;
	}
	return (1);
}

int	revra(t_node **a, int pr)
{
	if (ft_revrotate(a) == 0)
		return (0);
	if (pr)
		ft_printf("rra\n");
	return (1);
}

int	ft_revrb(t_node **b, int pr)
{
	if (ft_revrotate(b) == 0)
		return (0);
	if (pr)
		ft_printf("rrb\n");
	return (1);
}

int	ft_revrr(t_node **a, t_node **b, int pr)
{
	if (list_length(*a) <= 1 || list_length(*b) <= 1)
		return (0);
	ft_revrotate(a);
	ft_revrotate(b);
	if (pr)
		ft_printf("rrr\n");
	return (1);
}
