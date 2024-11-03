/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:20:29 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/03 06:03:27 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	int		chars_pr;
	va_list	args;

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
}

int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar_fd(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_fd(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}
