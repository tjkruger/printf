/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:31 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/11 13:22:43 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long format, int uppercase, int *chars_pr)
{
	char	*digits;
	char	hexdigits[16];
	int		i;

	i = 0;
	if (uppercase == 1)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (format == 0)
		ft_putchar('0', chars_pr);
	while (format)
	{
		hexdigits[i] = digits[format % 16];
		format /= 16;
		i++;
	}
	while (i-- > 0)
		ft_putchar(hexdigits[i], chars_pr);
	return (*chars_pr);
}
