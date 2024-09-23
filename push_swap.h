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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_arg
{
	int	argc;
	int	size_a;
	int	size_b;
}	t_arg;

//-----instructions---//
void	sa(int *a);
void	pa(int *a, int *b);
void	pb(int *a, int *b);
void	ra(int *a);
void	rra(int *a);
void	shrink(int *a, int size);
void	extend(int *a, int size);
//-----checker------//
int		ft_atoi(char *str);
void	checker(char *s[], int argc);
void	isasc(char *s[]);
void	isint(char *s[]);
void	issortedchar(char *s[]);
int		ft_strcmp(char *s1, char *s2);
//-----cria listas------//
int		*tratalista(int *a, int *b, int ac);
int		*crialistaa(char **a, int *l1, int argc);
void	push_swap(int *a, int *b, int argc);
//-------radix sort---------//
void	organize(int *a, int *b);
void	excep(int tam, int *a, int *b);
int		ops(int *a, int *b, int radix);
int		issortedint(int *s);
int		issortedintexcep(int *s);
int		isinv(int *s);
//-------helper funcs--------//
int		maximo(int *a);
void	ver(int *a, int *b);
void	error(void);
int		islowest(int *a, int i);
void	tratal(int *a, int *temp);
void	excep5(int *a, int *b);
void	excep4(int *a, int *b, int m);
void	excep3(int *a);
void	first(int *a, int *b);
void	last(int *a, int *b);

t_arg	*agrs(void);

#endif