/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:01:27 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/18 18:06:27 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	isasc(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		if (ft_strcmp(s[i], "") == 0)
			error();
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] < '0' || s[i][j] > '9') && s[i][j] != '-')
				error();
			if (s[i][j] == '-' && j != 0)
				error();
			j++;
		}
		i++;
	}
}

static void	isint(char *s[])
{
	int			i;
	long long	num;
	int			j;
	int			flag;

	i = 0;
	while (s[++i])
	{
		j = -1;
		num = 0;
		flag = 1;
		while (s[i][++j])
		{
			if (s[i][j] == '-')
			{
				flag = -1;
				if (s[i][j + 1] > 57 || s[i][j + 1] < 48)
					error();
			}
			else
				num = (num * 10 + (s[i][j] - 48));
		}
		if (num * flag > 2147483647 || num * flag < -2147483648)
			error();
	}
}

static void	issortedchar(char *s[])
{
	int	i;
	int	j;

	i = 2;
	j = 2;
	while (s[i])
	{
		if (ft_atoi(s[i - 1]) < ft_atoi(s[i]))
			j++;
		i++;
	}
	if (j == i)
		exit(1);
}

void	list_checker(char **s)
{
	int	i;
	int	j;

	i = 1;
	if (data()->ac < 2 || !s[i])
		error();
	isasc(s);
	isint(s);
	issortedchar(s);
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if ((ft_atoi(s[i]) == ft_atoi(s[j])))
				error();
			j++;
		}
		i++;
	}
}
