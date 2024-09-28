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

#include "../push_swap.h"

void	extend(int *a, int size)
{
	while (size > 0)
	{
		a[size] = a[size - 1];
		size--;
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

void	ra(void)
{
	int	i;
	int	temp;

	i = 0;
	if (data()->size_a > 0)
	{
		temp = data()->a[0];
		while (i < data()->size_a - 1)
		{
			data()->a[i] = data()->a[i + 1];
			i++;
		}
		data()->a[i] = temp;
	}
	write(1, "ra\n", 3);
}

void	rb(void)
{
	int	i;
	int	temp;

	i = 0;
	if (data()->size_b > 0)
	{
		temp = data()->b[0];
		while (i < data()->size_b - 1)
		{
			data()->b[i] = data()->b[i + 1];
			i++;
		}
		data()->b[i] = temp;
	}
	write(1, "rb\n", 3);
}

void	pb(void)
{
	if (data()->a)
	{
		extend(data()->b, data()->size_b);
		data()->b[0] = data()->a[0];
		shrink(data()->a, data()->size_a);
		data()->size_b++;
		data()->size_a--;
	}
	write(1, "pb\n", 3);
}
