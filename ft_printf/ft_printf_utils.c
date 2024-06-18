/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:48 by tmontani          #+#    #+#             */
/*   Updated: 2024/06/18 14:19:26 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int    ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}
int ft_putstr(char *str)
{
    int i;

    i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}

int	ft_handle_uint(unsigned int n)
{
    if (n < 0)
        n = n * (-1);
	if (n >= 10)
		return (ft_handle_uint(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}

int	ft_handle_int(unsigned int n)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		len += ft_handle_int(nbr / 10);
		nbr %= 10;
	}
	len += ft_putchar(nbr + '0');
	return (len);
}

int ft_lenght_hex(unsigned int nb)
{
	int len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	len--;
	return (len);
}

char *ft_itoa_hex(unsigned int nb, int len, char X_or_x)
{
	char *str;
	char hexa_upper[] = "0123456789ABCDEF";
	char hexa_lower[] = "0123456789abcdef";
	int	i;
	char temp;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	
	while (nb > 0)
	{
		if (X_or_x == 'X')
		{
			str[i] = hexa_upper[nb % 16];
			nb = nb / 16;
			i++;
		}
		else if (X_or_x == 'x')
		{
			str[i] = hexa_lower[nb % 16];
			nb = nb / 16;
			i++;
		}
	}
	str[i] = '\0';
	i = 0;
	len = ft_strlen2(str) - 1;
	while(i < len)
	{
		temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
	}
	return (str);
}

int ft_handle_hex(unsigned int nb, char X_or_x)
{
	int len;

	len = ft_lenght_hex(nb);
	ft_itoa_hex(nb, len, X_or_x);
	return (len);
}

int	ft_putnbr_hex(unsigned long long ptr)
{
	int len;
	char hex[] = "012456789abcdef";

	len = 0;
	if (ptr >= 16)
		len += ft_putnbr_hex(ptr / 16);
	len +=  ft_putchar(hex[ptr % 16]);
	return (len);
}

int	ft_handle_ptr(void *ptr)
{
	int len;
	
	len = 0;
	if (ptr)
	{
		ft_putstr("my adresse 0x");
		len = ft_putnbr_hex((unsigned long long)ptr);
		len = len + 2;
		return (len);
	}
	else
		ft_putstr("0x0");
		len = len + 3;
	return (len);
}
/*int main(void)
{
	char c;
	char *ptr;

	ptr = &c;
	printf("\n\n");
	printf("vraie adresse de ptr %p\n\n", ptr);
	ft_handle_ptr(ptr);
}*/
