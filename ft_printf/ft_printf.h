/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:45:20 by tmontani          #+#    #+#             */
/*   Updated: 2024/07/11 16:45:41 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_handle_uint(unsigned int n);
int		ft_handle_int(unsigned int n);
int		ft_lenght_hex(unsigned int nb);
char	*ft_itoa_hex(unsigned int nb, int len, char X_or_x);
int		ft_putnbr_hex(unsigned long long int n);
int		ft_handle_ptr(void *ptr);
int		ft_handle_hex(unsigned int nb, char X_or_x);
int		ft_strlen2(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
#endif
