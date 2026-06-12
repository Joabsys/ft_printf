/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesequie <jesequie@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-07 13:21:16 by jesequie          #+#    #+#             */
/*   Updated: 2026-06-07 13:21:16 by jesequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int				r;
	unsigned long	num;

	r = 0;
	num = 0;
	num = n;
	if (num >= 10)
		r += ft_print_unsigned(num / 10);
	r += ft_print_char(num % 10 + '0');
	return (r);
}
