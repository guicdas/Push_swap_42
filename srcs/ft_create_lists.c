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

#include "../push_swap.h"

static int	get_lowest_value(char **s)
{
	int	i;
	long long ret;
	int	lowest;

	i = 1;
	lowest = 0;
	ret = 2147483648;
	while (i <= data()->size_a)
	{
		if (ft_strcmp(s[i], "\2") && ret > ft_atoi(s[i]))
		{
			ret = ft_atoi(s[i]);
			lowest = i;
		}
		i++;
	}
	strcpy(s[lowest], "\2");
	return (lowest);
}

void	create_lists(char **s)
{
	int	i;

	i = 1;
	data()->a = ft_calloc(sizeof(int), data()->size_a);
	if (!data()->a)
		exit(1);
	data()->b = ft_calloc(sizeof(int), data()->size_a);
	if (!data()->b)
	{
		free(data()->a);
		exit(1);
	}
	data()->bf = ft_calloc(sizeof(int), data()->size_a);
	if (!data()->bf)
	{
		free(data()->b);
		free(data()->a);
		exit(1);
	}
	while (s[i])
		data()->a[get_lowest_value(s) - 1] = i++;
}
