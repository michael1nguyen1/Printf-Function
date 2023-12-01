/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:44:09 by linhnguy          #+#    #+#             */
/*   Updated: 2023/12/01 12:44:56 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(long n, int *c)
{
	char	b;

	if (n < 0)
	{
		(*c)++;
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		if (printnbr(n / 10, c) == -1)
			return (-1);
	}
	b = n % 10 + '0';
	(*c)++;
	if (write(1, &b, 1) == -1)
		return (-1);
	return (*c);
}
