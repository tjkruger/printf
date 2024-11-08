/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:20:29 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/08 18:25:13 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion(char specifier, va_list args, int *chars_pr)
{
	char	per;

	per = '%';
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int), chars_pr));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *), chars_pr));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_putnbr(va_arg(args, int), chars_pr));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, unsigned long), chars_pr));
	else if (specifier == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int), chars_pr));
	else if (specifier == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0, chars_pr));
	else if (specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1, chars_pr));
	else if (specifier == '%')
		return (ft_putchar(va_arg(args, int), chars_pr));
	return (0);
}
// #include <stdio.h>

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
			handle_conversion(*format, args, &chars_pr);
		}
		else
		{
			ft_putchar(*format, &chars_pr);
		}
		format++;
	}
	va_end(args);
	return (chars_pr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	num;
// 	int	*ptr;
// 	int	ret1;
// 	int	ret2;

// 	num = 42;
// 	ptr = &num;
// 	// Test pointer printing with %p
// 	printf("Standard printf: %p\n", (void *)ptr);
// 	ft_printf("Custom ft_printf: %p\n", (void *)ptr);
// 	// Testing a null pointer for %p
// 	printf("Standard printf with NULL: %p\n", (void *)NULL);
// 	ft_printf("Custom ft_printf with NULL: %p\n", (void *)NULL);
// 	// Check return values (useful to test chars printed or errors)
// 	ret1 = printf("Return value test: %p\n", (void *)ptr);
// 	ret2 = ft_printf("Return value test: %p\n", (void *)ptr);
// 	printf("Standard printf returned: %d\n", ret1);
// 	printf("Custom ft_printf returned: %d\n", ret2);
// 	return (0);
// }
