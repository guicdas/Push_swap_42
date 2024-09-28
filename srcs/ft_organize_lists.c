/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:37:27 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/18 18:16:06 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_a_sorted_int(void)
{
	int	i;

	i = 0;
	while (i < data()->size_a - 1)
	{
		if (data()->a[i] > data()->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	calculate_average(void)
{
	int	i;

	i = 0;
	data()->average = 0;
	while (i < data()->size_a)
	{
		data()->average += data()->a[i];
		i++;
	}
	data()->average /= data()->size_a;
}

void	calculate_bestfriends(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < data()->size_b)
	{
		j = 0;
		while (j < data()->size_a)
		{
			if (data()->a[j] > data()->b[i])
			{
				data()->bf[i] = data()->a[j];
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	get_bestfriend_cost(int n)
{
	int	i;

	i = 0;
	while (i < data()->size_a)
	{
		if (n == data()->a[i])
		{
			if (i < data()->size_a / 2)
				return (i);
			else
				return (data()->size_a - i);
		}
		i++;
	}
	return (0);
}

static int	calculate_costs(int i)
{
	int	ret;

	ret = 0;
	if (i < data()->size_b / 2)
		ret += i;
	else
		ret += data()->size_b - i;
	ret += get_bestfriend_cost(data()->bf[i]);
	return (ret);
}

int	decide_operation(void)
{
	int	i;
	int	place;
	int	cost;
	int	previous;

	i = 0;
	place = 0;
	cost = 0;
	previous = 0;
	while (i < data()->size_b)
	{
		cost = calculate_costs(i);
		if (cost < previous)
		{
			place = i;
			previous = cost;
		}
		if (i == 0)
			previous = cost;
		i++;
	}
	return (place);
}