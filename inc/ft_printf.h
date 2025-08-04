/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:37:33 by hermarti          #+#    #+#             */
/*   Updated: 2025/08/04 15:59:36 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_printf_hex(char flag, unsigned int nb, int fd);
int	ft_printf_char(char c, int fd);
int	ft_printf_string(char *str, int fd);
int	ft_printf_pointer(unsigned long paddr, int fd);
int	ft_printf_decimal(int decimal, int fd);
int	ft_printf_interger(int interger, int fd);
int	ft_printf_uinterger(unsigned int interger, int fd);

#endif
