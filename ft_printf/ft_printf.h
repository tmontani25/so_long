/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teo18 <tmontani@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:45:20 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/03 00:04:42 by teo18            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_printf(const char *, ...);
int ft_putchar(char c);
int ft_putstr(char *str);
int	ft_handle_uint(unsigned int n);
int	ft_handle_int(unsigned int n);
int ft_lenght_hex(unsigned int nb);
char *ft_itoa_hex(unsigned int nb, int len, char X_or_x);
int	ft_putnbr_hex(unsigned long long int n);
int	ft_handle_ptr(void *ptr);
int ft_handle_hex(unsigned int nb, char X_or_x);


int ft_strlen(char *str);
int ft_putchar(char c);
int ft_putstr(char *str);


#endif
