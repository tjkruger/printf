/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:31 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/03 05:48:24 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthex(unsigned int format, int uppercase)
{
	char	*digits;
	char	buffer[9];
	int		i;
	int		chars_pr;

	i = 0;
	chars_pr = 0;
	if (uppercase)
		digits = "123456789ABCDEF";
	else
		digits = "123456789abcdef";
	if (format == 0)
	{
		chars_pr += ft_putchar('0');
		return (chars_pr);
	}
	while (format > 0)
	{
		buffer[i++] = digits[format % 16];
		format /= 16;
	}
	while (--i >= 0)
		chars_pr += ft_putchar(buffer[i]);
	return (chars_pr);
}
