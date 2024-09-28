/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:19:12 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/18 18:11:43 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_data	*data(void)
{
	static t_data	a;

	return (&a);
}

static void	organize_lists(void)
{
	
	while (data()->size_a > 5)
	{
		calculate_average();
		if (data()->a[0] < data()->average)
			pb();
		else
			ra();
	}
	sort_5();
	calculate_bestfriends();
	calculate_costs();
}

int	main(int ac, char **av)
{
	data()->ac = ac;
	data()->size_a = (ac - 1);
	data()->size_b = 0;
	list_checker(av);
	create_lists(av);
	organize_lists();
	free(data()->a);
	free(data()->b);
	free(data()->bf);
}
