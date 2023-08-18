/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:49:56 by pvong             #+#    #+#             */
/*   Updated: 2023/03/11 13:48:02 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Char & str */
int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_get_format(va_list args, char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (specifier == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (specifier == 'x' || specifier == 'X')
		len += ft_printhex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'u')
		len += ft_printunbr(va_arg(args, unsigned int));
	else if (specifier == 'p')
		len += ft_printptr(va_arg(args, unsigned long));
	else if (specifier == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_get_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
