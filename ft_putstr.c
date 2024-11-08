/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:06:40 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/08 16:59:34 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *chars_pr)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s && *chars_pr != -1)
	{
		ft_putchar(*s, chars_pr);
		count++;
		s++;
	}
	return (count);
}
