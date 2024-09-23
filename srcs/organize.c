/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:37:27 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/18 18:16:06 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issortedint(int *s)
{
	int	i;

	i = 0;
	while (i < agrs()->size_a - 1)
	{
		if (s[i] > s[i + 1])
			return (0);
		i++;
	}
	return (agrs()->size_b == 0);
}

int	issortedintexcep(int *s)
{
	int	i;

	i = 0;
	while (i < agrs()->size_a - 1)
	{
		if (s[i] > s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	maxrad(int *a)
{
	int	i;
	int	max;

	i = 1;
	max = maximo(a);
	while (i < max)
		i *= 2;
	return (i);
}

int	ops(int *a, int *b, int radix)
{
	int	p;

	p = agrs()->size_a;
	while (p)
	{
		if (issortedint(a))
			return (-1);
		if (a[0] >> radix & 1)
			ra(a);
		else
			pb(a, b);
		p--;
	}
	while (agrs()->size_b > 0)
		pa(a, b);
	return (1);
}

void	organize(int *a, int *b)
{
	int	radix;

	radix = 0;
	if (agrs()->argc <= 6)
	{
		excep(agrs()-> argc - 1, a, b);
		return ;
	}
	while (radix < 32 && !issortedint(a))
	{
		ops(a, b, radix);
		radix++;
	}
}
