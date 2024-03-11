/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denrodri <denrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:59:04 by denrodri          #+#    #+#             */
/*   Updated: 2024/01/28 19:48:39 by denrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_putbase(unsigned long long n, size_t *counter, char *base)
{
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putbase(n / base_len, counter, base);
		ft_putbase(n % base_len, counter, base);
	}
	else
		ft_putchar(base[n], counter);
}
