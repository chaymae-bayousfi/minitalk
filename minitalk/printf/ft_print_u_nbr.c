/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:53:46 by cbayousf          #+#    #+#             */
/*   Updated: 2025/01/18 13:42:32 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u_nbr(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
	{
		count += ft_print_u_nbr(u / 10);
		count += ft_print_char(u % 10 + '0');
	}
	else
		count += ft_print_char(u + '0');
	return (count);
}
