/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:07:32 by aserbest          #+#    #+#             */
/*   Updated: 2024/11/13 15:12:44 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_hexadecimal(unsigned int n, char *hex);
int	ft_pointer(unsigned long n, char *hex);
int	ft_ptr_hex(unsigned long n, char *hex);
int	ft_putnbr(int n);
int	ft_u_putnbr(unsigned int n);

#endif
