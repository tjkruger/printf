/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:50:21 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/08 12:22:52 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *chars_pr)
{
	int	result;

	if (*chars_pr == -1)
		return (-1);
	result = write(1, &c, 1);
	if (result == -1)
		*chars_pr = -1;
	else
		*chars_pr += result;
	return (result);
}
