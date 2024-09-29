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

#include "../push_swap.h"

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

int	is_a_inverted(void)
{
	int	i;

	i = 0;
	while (i < data()->size_a - 1)
	{
		if (data()->a[i] < data()->a[i + 1])
			return (0);
		i++;
	}
	sa();
	rra();
	return (1);
}

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
