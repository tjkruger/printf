/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:20:29 by tjkruger          #+#    #+#             */
/*   Updated: 2024/10/31 13:00:25 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count_char;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				count_char += ft_putchar_fd((char)va_arg(args, int));
			else if (*format == 'd')
				count_char += ft_putnbr_fd(va_arg(args, int));
		}
	}
	va_end(args);
	return (0);
}
