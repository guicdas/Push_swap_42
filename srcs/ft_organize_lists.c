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
	while(data()->a[i])
	{
		data()->average += data()->a[i];
		i++;
	}
	data()->average /= data()->size_a;
}