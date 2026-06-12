/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesequie <jesequie@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-06-07 13:01:00 by jesequie          #+#    #+#             */
/*   Updated: 2026-06-07 13:01:00 by jesequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	aux_specifier(char s, va_list *args)
{
	if (s == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (s == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (s == 'd')
		return (ft_print_decimal(va_arg(*args, int)));
	else if (s == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int )));
	else if (s == 'i')
		return (ft_print_decimal(va_arg(*args, int)));
	else if (s == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0));
	else if (s == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1));
	else if (s == '%')
		return (ft_print_per());
	else if (s == 'p')
		return (ft_print_ptr((unsigned long long)va_arg(*args, void *)));
	return (0);
}

int	ft_printf(const char *specifier, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, specifier);
	while (*specifier)
	{
		if (*specifier == '%')
		{	
			specifier++;
			count += aux_specifier(*specifier, &args);
		}
		else
		{
			count++;
			write (1, &(*specifier), 1);
		}
		specifier++;
	}
	va_end(args);
	return (count);
}
