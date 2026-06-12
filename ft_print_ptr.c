/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesequie <jesequie@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-07 13:23:23 by jesequie          #+#    #+#             */
/*   Updated: 2026-06-07 13:23:23 by jesequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_print_aux_ptr(unsigned long n)
{
	char	*base;
	int		r;

	base = "0123456789abcdef";
	r = 0;
	if (n >= 16)
		r += ft_print_aux_ptr(n / 16);
	r += ft_print_char(base[n % 16]);
	return (r);
}

int	ft_print_ptr(unsigned long long n)
{
	int	sgn;

	sgn = 0;
	if (n == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	sgn = ft_print_aux_ptr(n);
	return (sgn + 2);
}
