/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linknode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:32:16 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:50:22 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_index(t_node **a)
{
	int		min;
	t_node	*t;
	int		index;

	min = get_minim(*a);
	t = *a;
	index = 0;
	while (t)
	{
		if (t->index == -1 && t->data == min)
		{
			t->index = index;
			index++;
			t = *a;
			min = get_minim(*a);
		}
		else
			t = t->next;
	}
}

int	get_minim(t_node *h)
{
	t_node	*t;
	int		m;

	t = h;
	if (!t)
		return (-1);
	m = 2147483647;
	while (t)
	{
		if (t->index == -1 && m > t->data)
			m = t->data;
		t = t->next;
	}
	return (m);
}

void	ft_init_stack(t_node **a, int ac, char **av)
{
	int		i;
	char	**s;
	t_node	*n;

	i = 0;
	s = 0;
	if (ac == 2)
		s = ft_split(av[1], ' ');
	else
	{
		i = 1;
		s = av;
	}
	while (s[i])
	{
		n = newlist(ft_atoi(s[i]));
		listadd_back(a, n);
		i++;
	}
	if (ac == 2)
		ft_free(s);
	ft_index(a);
}
