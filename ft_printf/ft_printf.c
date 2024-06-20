/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:44:47 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/20 13:25:59 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char type, void *arg)
{
	int	i;

	i = 0;
	if (type == 'c' || type == '%')
	{
		if (type == 'c')
			i += ft_putchar(*((char *)arg));
		else if (type == '%')
			i += ft_putchar('%');
	}
	if (type == 's')
		i += ft_putstr((char *)arg);
	if (type == 'p')
		ft_handle_ptr((void *)(arg));
	if (type == 'd' || type == 'i')
		i += ft_handle_int((int)(intptr_t)arg);
	if (type == 'u')
		i += ft_handle_uint((unsigned int)(intptr_t)arg);
	if (type == 'x' || type == 'X')
		i += ft_handle_hex(*(unsigned int *)arg, type);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			j += check_type(str[i], va_arg(args, void *));
		}
		else
		{
			write (1, &str[i], 1);
			j++;
		}
		i++;
	}
	va_end(args);
	return (j);
}
/*int main (void)
{
	char c;
	char *ptr;
	int nb_char_printed;

	c = 'a';
	ptr = &c;
 nb_char_printed = ft_printf("adresse de c: %p", ptr);
	printf("\n\n");
	printf("nombre de char imprime: %d", nb_char_printed);
	return (0);
}*/