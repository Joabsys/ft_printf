/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesequie <jesequie@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-07 13:22:16 by jesequie          #+#    #+#             */
/*   Updated: 2026-06-07 13:22:16 by jesequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_print_hex(unsigned int n, int uppercase)
{
	char	*base;
	int		r;

	r = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		r += ft_print_hex(n / 16, uppercase);
	r += ft_print_char(base[n % 16]);
	return (r);
}
