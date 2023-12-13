/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_revrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:31:04 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:49:50 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	ft_swp_nbr(t_node **stk)
{
	t_node	*head;
	t_node	*next;
	int		index;
	int		data;

	if (list_length(*stk) <= 1)
		return (0);
	head = *stk;
	next = head->next;
	index = head->index;
	data = head->data;
	head->index = next->index;
	head->data = next->data;
	next->data = data;
	next->index = index;
	return (1);
}

int	sa(t_node **a, int pr)
{
	if (ft_swp_nbr(a) == 0)
		return (0);
	if (pr)
		ft_printf("sa\n");
	return (1);
}

int	sb(t_node **b, int pr)
{
	if (ft_swp_nbr(b) == 0)
		return (0);
	if (pr)
		ft_printf("sb\n");
	return (1);
}

int	ss(t_node **a, t_node **b, int pr)
{
	if ((list_length(*a) < 2) || (list_length(*b) < 2))
		return (0);
	ft_swp_nbr(a);
	ft_swp_nbr(b);
	if (pr)
		ft_printf("ss\n");
	return (1);
}
