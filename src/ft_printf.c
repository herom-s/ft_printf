/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:37:14 by hermarti          #+#    #+#             */
/*   Updated: 2025/07/31 17:42:43 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_printf_char(char c, const char **format, int fd)
{
	ft_putchar_fd(c, fd);
	(*format)++;
	return (1);
}

int	ft_printf_string(char *s, const char **format, int fd)
{
	size_t	i;

	i = 0;
	ft_putstr_fd(s, fd);
	while (s[i])
	{
		(*format)++;
		i++;
	}
	return (i);
}

int	ft_printf_point(void *p, const char **format, int fd)
{
	size_t	i;

	i = 0;
}

int	ft_printf(const char *format, ...)
{
	size_t	pcount;
	va_list	args;

	pcount = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format++ == '%')
		{
			if (*format == '\0')
				break ;
			if (*format == 'c')
			{
				pcount += ft_printf_char(va_arg(args, int), &format, 1);
			}
			else if (*format == 's')
			{
				pcount += ft_printf_string(va_arg(args, char *), &format, 1);
			}
			else if (*format == 'p')
			{
				pcount += ft_printf_pointer(va_arg(args, void *), &format, 1);
			}
		}
		format++;
	}
	va_end(args);
	return (pcount);
}
