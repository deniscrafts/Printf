/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denrodri <denrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:42:46 by denrodri          #+#    #+#             */
/*   Updated: 2024/01/28 18:42:57 by denrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, size_t *counter)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	(*counter)++;
	return (1);
}

void	ft_putstr(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, counter);
		str++;
	}
}

void	ft_putptr(void *ptr, size_t *counter)
{
	unsigned long long	ptr_returned;

	ptr_returned = (unsigned long long)ptr;
	ft_putstr("0x", counter);
	ft_putbase(ptr_returned, counter, BASE_LOWER);
}

void	ft_putnbr(long long int number, size_t *counter)
{
	if (number < 0)
	{
		ft_putchar('-', counter);
		ft_putnbr(-number, counter);
	}
	else
	{
		if (number > 9)
			ft_putnbr(number / 10, counter);
		ft_putchar('0' + number % 10, counter);
	}
}
