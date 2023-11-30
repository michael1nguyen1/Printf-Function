/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:46:58 by linhnguy          #+#    #+#             */
/*   Updated: 2023/11/30 18:55:58 by linhnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printc(char s)
{
	return (write(1, &s, 1));
}

int	prints(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (prints("(null)"));
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i ++;
	}
	return (i);
}

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

int	ft_speci(va_list arg, char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		return (printc(va_arg(arg, int)));
	else if (s == 's')
		return (prints(va_arg(arg, char *)));
	else if (s == 'x' || s == 'X')
		return (printx(va_arg(arg, unsigned int), s, &count));
	else if (s == 'i' || s == 'd')
		return (printnbr(va_arg(arg, int), &count));
	else if (s == 'u')
		return (printnbr(va_arg(arg, unsigned int), &count));
	else if (s == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (printx(va_arg(arg, unsigned long), s, &count) == -1)
			return (-1);
		return (count + 2);
	}
	else if (s == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		prtlen;
	int		check;

	i = 0;
	prtlen = 0;
	va_start(arg, s);
	check = 0;

	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			if (write(1, &s[i], 1) == -1)
				return (-1);
			prtlen++;
			i++;
		}
		if (s[i] && s[i] == '%')
		{
			i++;
			check = ft_speci(arg, s[i]);
			if (check == -1)
				return (-1);
			prtlen += check;
			i++;
		}
	}
	va_end(arg);
	return (prtlen);
}

// int	main(void)
// {
// 	printf("%i\n", ft_printf("%x\n", 123));
// 	printf("%i\n", printf("%x\n", 123));
// }
