/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:36:05 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:51:36 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sorted(t_node **a, t_node **b)
{
	if (list_length(*a) <= 5)
		easysort(a, b);
	else
		radix_algo(a, b);
}

int	main(int ac, char **av)
{
	t_node	**a;
	t_node	**b;

	if (ac < 2)
		return (0);
	ft_arg_is_valid(ac, av);
	a = (t_node **)malloc(sizeof(t_node));
	b = (t_node **)malloc(sizeof(t_node));
	*a = 0;
	*b = 0;
	ft_init_stack(a, ac, av);
	if (issorted(a) == 1)
	{
		stack_free(a);
		stack_free(b);
		exit(0);
	}
	ft_sorted(a, b);
	return (0);
}
