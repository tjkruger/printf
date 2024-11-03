/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:20:29 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/03 05:35:59 by tjkruger         ###   ########.fr       */
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
			if (*format == 'c')
				chars_pr += ft_putchar_fd((char)va_arg(args, int));
			else if (*format == 'd')
				chars_pr += ft_putnbr_fd(va_arg(args, int));
			else if (*format == 's')
				chars_pr += ft_putstr(va_arg(args, char *));
			else if (*format == 'x')
				chars_pr += ft_puthex(va_arg(args, unsigned int), 0);
			else if (*format == 'X')
				chars_pr += ft_puthex(va_arg(args, unsigned int), 1);
			else if (*format == '%')
				chars_pr += ft_putchar('%');
		}
		va_end(args);
		return (0);
	}
}
