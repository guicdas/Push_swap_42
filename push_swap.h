/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:33:29 by gcatarin          #+#    #+#             */
/*   Updated: 2023/06/18 17:12:31 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

typedef struct s_data
{
	int	*a;
	int	*b;
	int	*bf;

	int		size_a;
	int		size_b;
	double	average;
}	t_data;

t_data	*data(void);

//-----	instructions	-----//
void	sa(void);
void	pa(void);
void	pb(void);
void	ra(void);
void	rb(void);
void	rra(void);
void	rrb(void);
void	shrink(int *a, int size);
void	extend(int *a, int size);

//-----	lists	-----//
void	list_checker(int ac, char **s);
void	create_lists(char **s);
void	calculate_average(void);

//-----	helper functions	-----//
void	debug(void);
void	error(void);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(char *dest, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

//-----	is sorted	-----//
int		is_a_sorted_int(void);
int		is_a_inverted(void);
void	sort_5(void);
void	calculate_bestfriends(void);
int		decide_operation(void);
