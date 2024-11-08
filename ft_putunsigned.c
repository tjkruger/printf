/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 06:03:54 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/08 12:39:29 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int num, int *chars_pr)
{
	char	buffer[10];
	int		i;

	if (*chars_pr == -1)
		return (-1);
	i = 0;
	if (num == 0)
		return (ft_putchar('0', chars_pr));
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (--i >= 0)
		ft_putchar(buffer[i], chars_pr);
	return (0);
}
