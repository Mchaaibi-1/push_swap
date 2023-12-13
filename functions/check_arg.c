/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaaibi <mchaaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:31:51 by mchaaibi          #+#    #+#             */
/*   Updated: 2023/12/12 20:50:11 by mchaaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isnbr(char *nb)
{
	int	i;

	i = 0;
	if (nb[0] == '-' || nb[0] == '+')
		i++;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isdupl(int nb, char **agv, int i)
{
	i++;
	while (agv[i])
	{
		if (ft_atoi(agv[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_errore(void)
{
	ft_printf("ERRORE\n");
	exit(0);
}

void	ft_arg_is_valid(int agc, char **agv)
{
	int		i;
	long	t;
	char	**str;

	i = 0;
	if (agc == 2)
		str = ft_split(agv[1], ' ');
	else
	{
		i = 1;
		str = agv;
	}
	while (str[i])
	{
		t = ft_atoi(str[i]);
		if (!ft_isnbr(str[i]))
			ft_errore();
		if (ft_isdupl(t, str, i))
			ft_errore();
		i++;
	}
	if (agc == 2)
		ft_free(str);
}
