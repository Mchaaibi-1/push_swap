/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdx_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:36:40 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:51:16 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_maxim_bits(t_node **a)
{
	int			max;
	int			maxbits;
	t_node		*head;

	head = *a;
	max = head->index;
	maxbits = 0;
	while (head)
	{
		if (max < head->index)
			max = head->index;
		head = head->next;
	}
	while (max >> maxbits)
		maxbits++;
	return (maxbits);
}

void	radix_algo(t_node **a, t_node **b)
{
	int		i;
	int		j;
	int		maxbits;
	int		lenght;
	t_node	*head_a;

	maxbits = get_maxim_bits(a);
	i = 0;
	lenght = list_length(*a);
	while (i < maxbits)
	{
		j = 0;
		while (j < lenght)
		{
			head_a = *a;
			if (((head_a->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pushb(a, b, 1);
			j++;
		}
		while (list_length(*b))
			pusha(a, b, 1);
		i++;
	}
}
