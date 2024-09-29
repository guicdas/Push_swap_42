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

#include "../push_swap.h"

void	sa(void)
{
	int	temp;

	if (data()->a)
	{
		temp = data()->a[0];
		data()->a[0] = data()->a[1];
		data()->a[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	rra(void)
{
	int	temp;

	if (data()->a)
	{
		temp = data()->a[data()->size_a - 1];
		extend(data()->a, data()->size_a);
		data()->a[0] = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(void)
{
	int	temp;

	if (data()->b)
	{
		temp = data()->b[data()->size_b - 1];
		extend(data()->b, data()->size_b - 1);
		data()->b[0] = temp;
		write(1, "rrb\n", 4);
	}
}

void	pa(void)
{
	if (data()->b)
	{
		extend(data()->a, data()->size_a);
		data()->a[0] = data()->b[0];
		shrink(data()->b, data()->size_b);
		data()->size_a++;
		data()->size_b--;
		write(1, "pa\n", 3);
	}
}
