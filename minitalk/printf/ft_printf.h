/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbayousf <cbayousf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:25:08 by cbayousf          #+#    #+#             */
/*   Updated: 2025/01/18 13:43:20 by cbayousf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_ptr(void *p);
int	ft_print_nbr(int d);
int	ft_print_u_nbr(unsigned int u);
int	ft_print_x_nbr(unsigned int x, char c);
#endif
