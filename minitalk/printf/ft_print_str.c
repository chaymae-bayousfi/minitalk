/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:47:30 by cbayousf          #+#    #+#             */
/*   Updated: 2025/01/18 13:42:37 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count = write(1, "(null)", 6);
		return (count);
	}
	while (*str)
	{
		count += ft_print_char(*str);
		str++;
	}
	return (count);
}
