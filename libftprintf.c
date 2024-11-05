/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:20:29 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/05 16:31:44 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'i' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'p')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (write(1, &"%", 1));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		chars_pr;
	va_list	args;

	chars_pr = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			chars_pr += handle_conversion(*format, args);
		}
		va_end(args);
		return (0);
	}
	return (0);
}
