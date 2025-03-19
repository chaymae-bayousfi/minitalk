/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:29:32 by cbayousf          #+#    #+#             */
/*   Updated: 2025/01/18 13:42:53 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int d)
{
	int	count;

	count = 0;
	if (d == -2147483648)
	{
		count += ft_print_str("-2147483648");
		return (count);
	}
	else if (d < 0)
	{
		count += ft_print_char('-');
		d = -d;
		count += ft_print_nbr(d);
	}
	else if (d > 9)
	{
		count += ft_print_nbr(d / 10);
		count += ft_print_nbr(d % 10);
	}
	else
		count += ft_print_char(d + '0');
	return (count);
}
