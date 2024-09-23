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

#include "push_swap.h"

int	ft_atoi(char *str)
{
	long int	num;
	int			flag;

	flag = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		str++;
		flag = -1;
	}
	else if (*str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		num = num * 10 + (flag * (*str++ - 48));
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
	}
	return (num);
}

void	isasc(char *s[])
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

void	isint(char *s[])
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

void	issortedchar(char *s[])
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

void	checker(char *s[], int argc)
{
	int	i;
	int	j;

	i = 1;
	if (!s[i] || argc < 2)
		exit(1);
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
