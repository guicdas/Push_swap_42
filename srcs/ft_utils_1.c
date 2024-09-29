#include "../push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	debug()
{
	int	i;

	printf("\nA: %d\tB: %d\n", data()->size_a, data()->size_b);
	i = 0;
	while (i <18)
	{
		if (data()->a[i])
			printf("%d", data()->a[i]);
		if (data()->b[i])
			printf("\t%d\t%d\n", data()->b[i], data()->bf[i]);
		else
			printf("\n");
		i++;
	}
	printf("\n");
}

int	ft_atoi(char *str)
{
	long long	num;
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

void	*ft_memset(char *dest, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = c;
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*dst;

	total = count * size;
	if (total == (size_t)-1)
		return (NULL);
	dst = malloc(total);
	if (dst == NULL)
		return (dst);
	ft_memset(dst, 0, total);
	return (dst);
}
