/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:19:30 by cbayousf          #+#    #+#             */
/*   Updated: 2025/01/20 17:12:42 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (c == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_print_u_nbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_print_x_nbr(va_arg(args, unsigned int), c);
	else if (c == '%')
		count += ft_print_char('%');
	else
		count += ft_print_char(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = write(1, "", 0);
	if (count != -1)
	{
		count = 0;
		while (str[i])
		{
			if (str[i] == '%' && str[i + 1])
				count += ft_format(args, str[++i]);
			else if (str[i] != '%')
				count += ft_print_char(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
