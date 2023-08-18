/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:41:26 by pvong             #+#    #+#             */
/*   Updated: 2023/03/11 13:48:12 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* PTR */
int	ft_ptr_len(uintptr_t n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd(n - 10 + 'a', 1);
}

int	ft_printptr(unsigned long long n)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (n == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	else
	{
		ft_put_ptr(n);
		len += ft_ptr_len(n);
	}
	return (len);
}
