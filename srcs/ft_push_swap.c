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

static int		get_bestfriend_equal(int j)
{
	int	i;

	i = 0;
	while (i < data()->size_a)
	{
		if (j == data()->a[i])
			return (i);
		i++;
	}
	return (0);
}

static void	put_b_on_top(int i)
{
	int counter;

	counter = i;
	if (counter > data()->size_b / 2)
	{
		while (counter++ != data()->size_b + 1)
			rrb();
	}
	else
	{
		while (counter--)
			rb();
	}
}

static void	put_a_on_top(int i)
{
	int counter;

	counter = get_bestfriend_equal(data()->bf[i]);
	if (counter > data()->size_a / 2)
	{
		while (counter++ != data()->size_a + 1)
			rra();
	}
	else
	{
		while (counter--)
			ra();
	}
}

static void	organize_lists(void)
{
	int	i;

	i = 0;
	while (data()->size_a > 5)
	{
		calculate_average();
		if (data()->a[0] < data()->average)
			pb();
		else
			ra();
	}
	sort_5();
	while (data()->size_b != 0)
	{
		calculate_bestfriends();
		i = decide_operation();
		put_b_on_top(i);
		put_a_on_top(i);
		pa();
	}
	while (data()->a[0] != 1)
		rra();
}

int	main(int ac, char **av)
{
	data()->size_a = ac - 1;
	data()->size_b = 0;
	list_checker(ac, av);
	create_lists(av);
	organize_lists();
	free(data()->a);
	free(data()->b);
	free(data()->bf);
}
