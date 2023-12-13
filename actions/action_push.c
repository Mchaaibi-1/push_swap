/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:27:53 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:49:48 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	int	ftpush(t_node **a, t_node **b)
{
	t_node	*elm;
	t_node	*next;

	if (list_length(*b) < 1)
		return (0);
	elm = *b;
	next = elm->next;
	listadd_front(a, elm);
	*b = next;
	elm = 0;
	free(elm);
	return (1);
}

int	pusha(t_node **a, t_node **b, int pr)
{
	if (ftpush(a, b) == 0)
		return (0);
	if (pr)
		ft_printf("pa\n");
	return (1);
}

int	pushb(t_node **a, t_node **b, int pr)
{
	if (ftpush(b, a) == 0)
		return (0);
	if (pr)
		ft_printf("pb\n");
	return (1);
}
