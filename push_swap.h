/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:36:20 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:51:36 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}		t_node;

void	ft_arg_is_valid(int argc, char **argv);
void	ft_exit(char *msg);
int		minindex(t_node **a, int min);
void	ft_free(char **str);
void	stack_free(t_node **s);
int		issorted(t_node **s);

void	easysort(t_node **a, t_node **b);

int		sa(t_node **a, int p);
int		sb(t_node **b, int p);
void	ft_init_stack(t_node **a, int ac, char **av);
int		pusha(t_node **a, t_node **b, int p);
int		pushb(t_node **a, t_node **b, int p);
void	radix_algo(t_node **a, t_node **b);
int		rb(t_node **b, int p);
int		ft_rr(t_node **a, t_node **b, int p);
int		revra(t_node **a, int p);
int		ra(t_node **a, int p);
int		ft_revrb(t_node **b, int p);
int		ft_revrr(t_node **a, t_node **b, int p);
t_node	*newlist(int data);
void	listadd_back(t_node **s, t_node *node);
t_node	*lastlist(t_node *h);
void	ft_show_lst(t_node *h);

void	listadd_front(t_node **s, t_node *node);
int		list_length(t_node *h);
int		get_minim(t_node *h);

#endif