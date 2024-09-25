/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:03:04 by gcatarin          #+#    #+#             */
/*   Updated: 2023/11/05 15:17:36 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	receive_instructs(int *a, int *b)
{
	
}

void	bonus_checker(int *a, int *b, int argc)
{
	a = tratalista(a, b, argc);
	receive_instructs(a, b);
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;

	checker(argv, argc);
	a = (int *)malloc(sizeof(int) * argc);
	if (!a)
		exit(1);
	b = (int *)malloc(sizeof(int) * argc);
	if (!b)
	{
		free(a);
		exit(1);
	}
	agrs()->argc = argc;
	agrs()->size_a = (argc - 1);
	agrs()->size_b = 0;
	a = crialistaa(argv, a, argc);
	bonus_checker(a, b, argc);
}