/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:34:54 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:53:07 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(char *m)
{
	ft_printf("%s \n", m);
	exit(0);
}

static int	ft_commonds(char *l, t_node **a, t_node **b)
{
	if (!(ft_strcmp(l, "sa\n")))
		sa(a, 0);
	else if (!(ft_strcmp(l, "sb\n")))
		sb(a, 0);
	else if (!(ft_strcmp(l, "ss\n")))
		ss(a, b, 0);
	else if (!(ft_strcmp(l, "ra\n")))
		ra(a, 0);
	else if (!(ft_strcmp(l, "rb\n")))
		rb(b, 0);
	else if (!(ft_strcmp(l, "rr\n")))
		ft_rr(a, b, 0);
	else if (!(ft_strcmp(l, "rra\n")))
		revra(a, 0);
	else if (!(ft_strcmp(l, "rra\n")))
		rrr(a, b, 0);
	else if (!(ft_strcmp(l, "rrb\n")))
		rrb(b, 0);
	else if (!(ft_strcmp(l, "pa\n")))
		pusha(a, b, 0);
	else if (!(ft_strcmp(l, "pb\n")))
		pushb(a, b, 0);
	else
		return (0);
	return (1);
}

static void	print_chekresult(t_node **a, t_node **b)
{
	if (issorted(a) && list_length(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (*a)
		stack_free(a);
	if (*b)
		stack_free(b);
}

int	main(int agc, char **agv)
{
	t_node		**a;
	t_node		**b;
	char		*line;

	if (agc < 2)
		return (0);
	ft_arg_is_valid(agc, agv);
	a = (t_node **)malloc(sizeof(t_node));
	b = (t_node **)malloc(sizeof(t_node));
	*a = NULL;
	*b = NULL;
	ft_init_stack(a, agc, agv);
	line = get_next_line(0);
	while (line)
	{
		if (!ft_commonds(line, a, b))
		{
			ft_exit("Error");
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	print_chekresult(a, b);
	return (1);
}
