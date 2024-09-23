/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:32:10 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/17 13:41:59 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *a)
{
	int	i;
	int	temp;

	i = 0;
	if (agrs()->size_a > 0)
	{
		temp = a[0];
		while (i < agrs()->size_a - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[i] = temp;
	}
	write(1, "ra\n", 3);
}

void	sa(int *a)
{
	int	temp;

	if (a)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	rra(int *a)
{
	int	temp;

	temp = a[agrs()->size_a - 1];
	extend(a, agrs()->size_a);
	a[0] = temp;
	write(1, "rra\n", 4);
}
