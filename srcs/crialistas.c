/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crialistas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:00:29 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/17 13:32:13 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*change(int *a)
{
	int	j;

	j = 0;
	while (j < agrs()->argc - 1)
	{
		if (a[j] > 0)
			a[j]++;
		else if (a[j] == 0)
			a[j] = 1;
		j++;
	}
	return (a);
}

int	*crialistaa(char **a, int *l1, int argc)
{
	int	i;
	int	zero;

	zero = 0;
	i = 0;
	while (i < agrs()->argc - 1)
	{
		l1[i] = ft_atoi(a[i + 1]);
		if (l1[i] == 0 && i < argc - 1)
			zero = i;
		i++;
	}
	if (zero > 0)
		l1 = change(l1);
	return (l1);
}

int	islowest(int *a, int i)
{
	int	j;

	j = 0;
	while (j < agrs()->argc - 1)
	{
		if (j == i)
			j++;
		else if (a[i] < a[j])
			j++;
		else
			return (-1);
	}
	return (i);
}

void	tratal(int *a, int *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < agrs()->argc - 1)
	{
		j = 0;
		temp[i] = 1;
		while (j < agrs()->argc - 1)
		{
			if (a[i] > a[j])
				temp[i]++;
			j++;
		}
		i++;
	}
}

int	*tratalista(int *a, int *b, int ac)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * ac);
	if (!temp)
	{
		free(a);
		free(b);
		exit(1);
	}
	tratal(a, temp);
	free(a);
	return (temp);
}
