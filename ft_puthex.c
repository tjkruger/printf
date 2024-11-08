/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 05:36:31 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/08 18:08:13 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long format, int uppercase, int *chars_pr)
{
	char	*digits;
	char	buffer[17];
	int		i;

	i = 0;
	if (uppercase)
		digits = "123456789ABCDEF";
	else
		digits = "123456789abcdef";
	if (format == 0)
		return (ft_putchar('0', chars_pr));
	while (format > 0)
	{
		buffer[i++] = digits[format % 16];
		format /= 16;
	}
	while (--i >= 0 && *chars_pr != -1)
		ft_putchar(buffer[i], chars_pr);
	if (*chars_pr == -1)
		return (-1);
	else
		return (1);
}
