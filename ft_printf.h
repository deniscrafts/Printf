/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denrodri <denrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:31:25 by denrodri          #+#    #+#             */
/*   Updated: 2024/01/29 15:21:22 by denrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_UPPER "0123456789ABCDEF"
# define BASE_LOWER "0123456789abcdef"

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c, size_t *counter);
void	ft_putstr(char *str, size_t *counter);
void	ft_putptr(void *ptr, size_t *counter);
void	ft_putnbr(long long int number, size_t *counter);

void	ft_putbase(unsigned long long n, size_t *counter, char *base);

void	ft_format(va_list va, const char *str, size_t *counter);

int		ft_printf(const char *str, ...);

#endif