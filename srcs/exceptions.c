/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:54:16 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/18 17:11:03 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	excep(int tam, int *a, int *b)
{
	if (tam == 2)
		ra(a);
	else if (tam == 3)
		excep3(a);
	else if (tam == 4)
		excep4(a, b, 4);
	else
		excep5(a, b);
}

void	excep3(int *a)
{
	if (issortedintexcep(a) != 0 || isinv(a) == 1)
		return ;
	if (a[1] < a[0])
	{
		if (a[2] > a[0])
			sa(a);
		else
			ra(a);
	}
	else
	{
		if (a[2] > a[0])
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
	return ;
}

void	check_lowest(int *a, int *b, int i, int m)
{
	if (i == 0)
		pb(a, b);
	else if (i == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if (i == 2)
	{
		ra(a);
		sa(a);
		pb(a, b);
	}
	else if (i == 3 && m == 5)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else
	{
		rra(a);
		pb(a, b);
	}
}

void	excep4(int *a, int *b, int m)
{
	int	i;

	i = 0;
	while (i < agrs()->size_a)
	{
		if (a[i] == 2 && m == 5)
		{
			check_lowest(a, b, i, agrs()->size_a);
			break ;
		}
		if (a[i] == 1 && m == 4)
		{
			check_lowest(a, b, i, agrs()->size_a);
			break ;
		}
		else
			i++;
	}
	excep3(a);
	pa(a, b);
	return ;
}

void	excep5(int *a, int *b)
{
	int	i;

	i = 0;
	while (i < agrs()->size_a)
	{
		if (a[i] == 1)
		{
			check_lowest(a, b, i, agrs()->size_a);
			break ;
		}
		else
			i++;
	}
	excep4(a, b, 5);
	pa(a, b);
	return ;
}
