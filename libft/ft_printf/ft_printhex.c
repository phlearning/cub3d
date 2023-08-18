/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:21:27 by pvong             #+#    #+#             */
/*   Updated: 2023/03/11 13:48:06 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* HEX */
int	ft_hex_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_puthex(unsigned int n, char type)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, type);
		ft_puthex(n % 16, type);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else if (type == 'X')
		ft_putchar_fd(n - 10 + 'A', 1);
	else if (type == 'x')
		ft_putchar_fd(n - 10 + 'a', 1);
}

int	ft_printhex(unsigned int n, char type)
{
	int	len;

	len = ft_hex_len(n);
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(n, type);
	return (len);
}
