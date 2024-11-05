/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 06:03:54 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/05 15:30:49 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int num)
{
	char	buffer[10];
	int		i;
	int		printed_chars;

	i = 0;
	printed_chars = 0;
	if (num == 0)
		return (ft_putchar('0'));
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (--i >= 0)
		printed_chars += ft_putchar(buffer[i]);
	return (printed_chars);
}
