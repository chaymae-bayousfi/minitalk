/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:17:39 by cbayousf          #+#    #+#             */
/*   Updated: 2025/01/18 13:42:46 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_x_ptr(unsigned long p)
{
	int	count;

	count = 0;
	if (p >= 16)
	{
		count += ft_print_x_ptr(p / 16);
		count += ft_print_x_ptr(p % 16);
	}
	else if (p > 9)
		count += ft_print_char(p + 87);
	else
		count += ft_print_char(p + 48);
	return (count);
}

int	ft_print_ptr(void *p)
{
	int	count;

	count = 0;
	if (!p)
	{
		count += ft_print_str("0x0");
		return (count);
	}
	count += ft_print_str("0x");
	count += ft_print_x_ptr((unsigned long)p);
	return (count);
}
