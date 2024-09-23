/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:18:17 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/17 13:21:14 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extend(int *a, int size)
{
	int	i;

	i = size;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
}

void	shrink(int *a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = 0;
}

void	pa(int *a, int *b)
{
	if (b)
	{
		extend(a, agrs()->size_a);
		a[0] = b[0];
		shrink(b, agrs()->size_b);
		agrs()->size_a++;
		agrs()->size_b--;
		write(1, "pa\n", 3);
	}
}

void	pb(int *a, int *b)
{
	if (a)
	{
		extend(b, agrs()->size_b);
		b[0] = a[0];
		shrink(a, agrs()->size_a);
		agrs()->size_b++;
		agrs()->size_a--;
	}
	write(1, "pb\n", 3);
}
