/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:34:00 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:50:35 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//done

t_node	*lastlist(t_node *h)
{
	t_node	*t;

	t = h;
	if (!t)
		return (0);
	while (t->next)
		t = t->next;
	return (t);
}

t_node	*newlist(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->index = -1;
	node->next = 0;
	return (node);
}

void	listadd_front(t_node **s, t_node *node)
{
	node->next = *s;
	*s = node;
}

void	ft_show_lst(t_node *h)
{
	t_node	*t;

	t = h;
	if (!t)
		return ;
	while (t)
	{
		ft_printf("-->index : %d ; data : %d\n", t->index, t->data);
		t = t->next;
	}
}

void	listadd_back(t_node **s, t_node *node)
{
	t_node	*n;

	if (*s)
	{
		n = lastlist(*s);
		n->next = node;
	}
	else
	{
		*s = node;
		(*s)->next = NULL;
	}
}
