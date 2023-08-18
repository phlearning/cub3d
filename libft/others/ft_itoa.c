/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:19:24 by pvong             #+#    #+#             */
/*   Updated: 2022/10/17 14:21:24 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getnbdigits(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		++i;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoanegative(char *nb, int n, int i, int size)
{
	int	signe;

	signe = 1;
	if (n < 0)
		signe = -1;
	while (i < size && n <= 0)
	{
		nb[size - i - 1] = -(n % 10 - '0');
		n /= 10;
		i++;
	}
	if (signe < 0)
		nb[0] = '-';
	return (nb);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*nb;

	i = 0;
	size = ft_getnbdigits(n);
	nb = ft_calloc(size + 1, sizeof(char));
	if (!nb)
		return (NULL);
	if (n < 0)
	{
		nb = ft_itoanegative(nb, n, i, size);
		return (nb);
	}
	while (i < size && n >= 0)
	{
		nb[size - i - 1] = (n % 10 + '0');
		n /= 10;
		i++;
	}
	nb[i] = '\0';
	return (nb);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)	argc;
	int		a;
	char	*b;
	int		size;
	int		sizechar;

	a = atoi(argv[1]);
	b = ft_itoa(a);
	size = ft_getnbdigits(a);
	sizechar = ft_strlen(b);
	printf("nb: %d\n", a);
	printf("ft_itoa: %s\n", b);
	printf("size of nb: %d\n", size);
	printf("size of char: %d\n", sizechar);
	return (0);
}
*/
