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
	int ret;
	int	highest;

	i = 1;
	highest = 0;
	ret = -1;
	while (i < data()->size_a + 1)
	{
		if (ret < ft_atoi(s[i]))
		{
			ret = ft_atoi(s[i]);
			highest = i;
			
		}
		i++;
	}
	printf("highest %d - ret %d\n", highest, ret);
	return (highest);
}

static void	fill_list_a(char **s)
{
	int	i;
	int j;

	i = 0;
	j = 1;
	while (s[j])
	{
		data()->a[get_lowest_value(s)] = j;
		i++;
		j++;
	}
	debug();
}

void	create_lists(char **s)
{
	data()->a = ft_calloc(sizeof(int), data()->ac);
	if (!data()->a)
		exit(1);
	data()->b = ft_calloc(sizeof(int), data()->ac);
	if (!data()->b)
	{
		free(data()->a);
		exit(1);
	}
	data()->bf = ft_calloc(sizeof(int), data()->ac);
	if (!data()->bf)
	{
		free(data()->b);
		free(data()->a);
		exit(1);
	}
	fill_list_a(s);
}
