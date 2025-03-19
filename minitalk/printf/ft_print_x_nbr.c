/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:11:48 by cbayousf          #+#    #+#             */
/*   Updated: 2025/01/18 15:28:39 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_nbr(unsigned int x, char c)
{
	int		count;
	char	*base;

	count = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (x >= 16)
	{
		count += ft_print_x_nbr(x / 16, c);
		count += ft_print_char(base[x % 16]);
	}
	else
		count += ft_print_char(base[x]);
	return (count);
}
