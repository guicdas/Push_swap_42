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

#include "../push_swap.h"

static void	sort_3(void)
{
	if (is_a_inverted() || is_a_sorted_int())
		return ;
	else if (data()->a[1] < data()->a[0])
	{
		if (data()->a[2] > data()->a[0])
			sa();
		else
			ra();
	}
	else
	{
		if (data()->a[2] > data()->a[0])
		{
			sa();
			ra();
		}
		else
			rra();
	}
}

static int	get_lowest_place(void)
{
	int	i;
	int lowest;
	int ret;

	i = 0;
	lowest = data()->a[0];
	ret = 0;
	while (i < data()->size_a)
	{
		if (lowest > data()->a[i])
		{
			lowest = data()->a[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

static void	push_lowest_to_b(int i)
{
	if (i == 1)
		sa();
	else if (i == 2)
	{
		ra();
		ra();
	}
	else if (i == 3 && data()->size_a == 4)
		rra();
	else if (i == 3 && data()->size_a == 5)
	{
		rra();
		rra();
	}
	else if (i == 4)
		rra();
	pb();
}

void	sort_5(void)
{
	int	i;

	i = get_lowest_place();
	push_lowest_to_b(i);
	i = get_lowest_place();
	push_lowest_to_b(i);
	sort_3();
	pa();
	pa();
}
