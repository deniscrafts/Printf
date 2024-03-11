/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denrodri <denrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:30:11 by denrodri          #+#    #+#             */
/*   Updated: 2024/01/28 21:05:46 by denrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, const char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar(va_arg(va, int), counter);
	if (*str == 's')
		ft_putstr(va_arg(va, char *), counter);
	if (*str == 'p')
		ft_putptr(va_arg(va, void *), counter);
	if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(va, int), counter);
	if (*str == 'u')
		ft_putbase(va_arg(va, unsigned int), counter, "0123456789");
	if (*str == 'x')
		ft_putbase(va_arg(va, unsigned int), counter, BASE_LOWER);
	if (*str == 'X')
		ft_putbase(va_arg(va, unsigned int), counter, BASE_UPPER);
	if (*str == '%')
		ft_putchar(*str, counter);
}

int	ft_printf(const char *str, ...)
{
	size_t	counter;
	va_list	ap;

	counter = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(ap, str, &counter);
		}
		else
			ft_putchar(*str, &counter);
		str++;
	}
	return (counter);
}
