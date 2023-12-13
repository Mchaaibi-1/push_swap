/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:30:28 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:12:20 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_rotate_nbr(t_node **stk)
{
	t_node	*temp;
	t_node	*last;

	if (list_length(*stk) <= 1)
		return (0);
	temp = *stk;
	last = lastlist(*stk);
	*stk = temp->next;
	last->next = temp;
	temp->next = 0;
	return (1);
}

int	ra(t_node **a, int pr)
{
	if (ft_rotate_nbr(a) == 0)
		return (0);
	if (pr)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_node **b, int pr)
{
	if (ft_rotate_nbr(b) == 0)
		return (0);
	if (pr)
		ft_printf("rb\n");
	return (1);
}

int	ft_rr(t_node **a, t_node **b, int pr)
{
	if (list_length(*a) <= 1 || list_length(*b) <= 1)
		return (0);
	ft_rotate_nbr(a);
	ft_rotate_nbr(b);
	if (pr)
		ft_printf("rr\n");
	return (1);
}
