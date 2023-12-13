/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:36:59 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:51:36 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_suit3(t_node *h, t_node **a, int min)
{
	if (h->index != min && h->index != (2 + min))
	{
		if (h->next->index == (2 + min))
			revra(a, 1);
		else
			sa(a, 1);
	}
}

static	void	ft_sort3(t_node **a, int min)
{
	t_node	*head_a;

	head_a = *a;
	if (issorted(a))
		return ;
	if (head_a->index == min)
	{
		ra(a, 1);
		sa(a, 1);
		revra(a, 1);
	}
	else if (head_a->index == (2 + min))
	{
		if (head_a->next->index == min)
			ra(a, 1);
		else
		{
			sa(a, 1);
			revra(a, 1);
		}
	}
	else
		ft_suit3(head_a, a, min);
}

static void	ft_sort4(t_node **a, t_node **b, int min)
{
	int	index_zero;

	index_zero = minindex(a, min);
	if (index_zero == 1)
		sa(a, 1);
	else if (index_zero == 2 || index_zero == 3)
	{
		revra(a, 1);
		if (index_zero == 2)
			revra(a, 1);
	}
	if (issorted(a))
		return ;
	pushb(a, b, 1);
	ft_sort3(a, 1 + min);
	pusha(a, b, 1);
}

static void	ft_sort5(t_node **a, t_node **b)
{
	int	index_zero;

	index_zero = minindex(a, 0);
	if (index_zero == 1)
		sa(a, 1);
	else if (index_zero == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (index_zero == 3)
	{
		revra(a, 1);
		revra(a, 1);
	}
	else if (index_zero == 4)
		revra(a, 1);
	if (issorted(a))
		return ;
	pushb(a, b, 1);
	ft_sort4(a, b, 1);
	pusha(a, b, 1);
}

void	easysort(t_node **a, t_node **b)
{
	int	length;

	length = list_length(*a);
	if (length == 2)
		sa(a, 1);
	else if (length == 3)
		ft_sort3(a, 0);
	else if (length == 4)
		ft_sort4(a, b, 0);
	else if (length == 5)
		ft_sort5(a, b);
	length = list_length(*b);
}
