/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excephelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:05:05 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/18 17:10:16 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first(int *a, int *b)
{
	pa(a, b);
	sa(a);
}

void	last(int*a, int *b)
{
	pa(a, b);
	ra(a);
}

int	ft_strcmp(char *str1, char *str2)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str1[n])
		n++;
	while (str1[i] && str1[i] == str2[i])
		i++;
	if (n == i)
		return (0);
	return (str1[i] - str2[i]);
}

t_arg	*agrs(void)
{
	static t_arg	a;

	return (&a);
}

int	isinv(int *s)
{
	int	i;

	i = 0;
	while (i < agrs()->size_a - 1)
	{
		if (s[i] < s[i + 1])
			return (0);
		i++;
	}
	sa(s);
	rra(s);
	return (1);
}
