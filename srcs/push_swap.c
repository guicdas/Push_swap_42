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

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
/*
void	ver(int *a, int *b)
{
	int	i;

	printf("\nA: %i\n", agrs()->size_a);
	i = 0;
	while (i < agrs()->size_a)
		{printf("%d\n", a[i]);i++;}
	i = 0;
	printf("\nB: %i\n", agrs()->size_b);
	while (i < agrs()->size_b)
		{printf("%d\n", b[i]);i++;}
	printf("\n");
}*/

int	maximo(int *a)
{
	int	j;
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	j = i + 1;
	while (i < agrs()->argc - 2)
	{
		if (a[i] > a[j])
			j++;
		else
		{
			i = j++;
			ret = a[i];
		}
		if (j >= agrs()->argc - 2)
			break ;
	}
	return (ret);
}

void	push_swap(int *a, int *b, int argc)
{
	a = tratalista(a, b, argc);
	organize(a, b);
	free(a);
	free(b);
}

int	main(int argc, char *argv[])
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
	push_swap(a, b, argc);
}
