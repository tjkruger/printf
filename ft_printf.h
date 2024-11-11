/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjkruger <tjkruger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:15:17 by tjkruger          #+#    #+#             */
/*   Updated: 2024/11/08 18:24:22 by tjkruger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c, int *chars_pr);
int	ft_puthex(unsigned long format, int uppercase, int *chars_pr);
int	ft_putnbr(int n, int *chars_pr);
int	ft_putstr(char *s, int *chars_pr);
int	ft_putunsigned(unsigned int num, int *chars_pr);
int	ft_putptr(unsigned long ptr, int *chars_pr);

#endif
