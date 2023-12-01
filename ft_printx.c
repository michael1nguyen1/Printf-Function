/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:45:37 by linhnguy          #+#    #+#             */
/*   Updated: 2023/12/01 14:27:08 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printx(unsigned long n, char s, int *c)
{
	char	*hexlow;
	char	*hexup;

	hexlow = "0123456789abcdef";
	hexup = "0123456789ABCDEF";
	if (n > 15)
	{
		if (printx(n / 16, s, c) == -1)
			return (-1);
	}
	if (s == 'x' || s == 'p')
	{
		(*c)++;
		if (write (1, &hexlow[n % 16], 1) == -1)
			return (-1);
	}
	if (s == 'X')
	{
		(*c)++;
		if (write (1, &hexup[n % 16], 1) == -1)
			return (-1);
	}
	return (*c);
}
