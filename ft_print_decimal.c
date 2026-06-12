/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesequie <jesequie@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-07 13:20:25 by jesequie          #+#    #+#             */
/*   Updated: 2026-06-07 13:20:25 by jesequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(long long n)
{
	long long	num;
	int			r;

	r = 0;
	num = 0;
	if (n < 0)
	{
		r++;
		write (1, "-", 1);
		num = n * -1;
	}
	else
		num = n;
	if (num >= 10)
		r += ft_print_decimal (num / 10);
	r += ft_print_char (num % 10 + '0');
	return (r);
}
