/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:03:10 by marvin            #+#    #+#             */
/*   Updated: 2024/04/29 12:03:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	many_characters(int nbr, int base, int which)
{
	int			nums;
	long long	nb;

	nums = 0;
	if (which == 1)
		nb = nbr;
	if (which == 2)
		nb = (unsigned int)nbr;
	if (nb < 0)
	{
		nb = -nb;
		nums++;
	}
	while (nb >= base)
	{
		nb = nb / base;
		nums++;
	}
	if (nb < base)
		nums++;
	return (nums);
}

int	which_use1(const char *format, va_list args)
{
	int				result;
	unsigned long	entrence;

	result = 0;
	entrence = va_arg(args, unsigned long);
	if (*format == 'x')
	{
		ft_print_x(entrence);
		result = many_characters(entrence, 16, 2);
	}
	else if (*format == 'X')
	{
		ft_printupperhexa(entrence);
		result = many_characters(entrence, 16, 2);
	}
	else if (*format == 'p')
		return (ft_printpointer(entrence));
	else if (*format == 'u')
	{
		ft_unsignedint(entrence);
		result = many_characters(entrence, 10, 2);
	}
	return (result);
}

int	which_use2(const char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	which_use3(va_list args)
{
	int				result;
	unsigned int	entrence;

	entrence = va_arg(args, int);
	ft_putnbr(entrence);
	result = many_characters(entrence, 10, 1);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		num_c;
	va_list	args;

	num_c = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'x' || *format == 'X'
				|| *format == 'u' || *format == 'p')
				num_c += which_use1(format, args) - 1;
			if (*format == 'c' || *format == 's' || *format == '%')
				num_c += which_use2(format, args) - 1;
			if (*format == 'd' || *format == 'i')
				num_c += which_use3(args) - 1;
		}
		else
			ft_putchar(*format);
		format++;
		num_c++;
	}
	va_end(args);
	return (num_c);
}

/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("|%p| ", LONG_MIN);
	ft_printf("%p ", LONG_MIN);
	printf("\n|%p| ", LONG_MAX);
	ft_printf("%p ", LONG_MAX);
	printf("\n|%p| ", 0);
	ft_printf("%p ", 0);
	printf("\n|%p| ", ULONG_MAX);
	ft_printf("%p ", ULONG_MAX);
	printf("\n|%p| ", -ULONG_MAX);
	ft_printf("%p ", -ULONG_MAX);
	return (0);
}
*/
/*
#include <stdio.h>
int	main(void)
{
	void	*test = "test";

	printf("%d ", ft_printf("teste max ft_printf\n"));
	printf("%d ", ft_printf("PORCENTAGEM:|%%|\n") - 15);
	printf("%d ", ft_printf("CARACTER: |%c|\n", 'x') - 13);
	printf("%d ", ft_printf("STRING: |%s|\n", "teste str") - 11);
	printf("%d ", ft_printf("INTEIRO: |%i|\n", -2147483648) - 12);
	printf("%d ", ft_printf("DECIMAL: |%d|\n", -2147483648) - 12);
	printf("%d ", ft_printf("UNSIGNED INT: |%u|\n", 3147483648) - 17);
	printf("%d ", ft_printf("HEXA LOW: |%x|\n", 123221) - 13);
	printf("%d ", ft_printf("HEXA UP: |%X|\n", 123221) - 12);
	printf("%d ", ft_printf("NEG HEXA LOW: |%x|\n", -123221) - 17);
	printf("%d ", ft_printf("NEG HEXA UP: |%X|\n", -123221) - 16);
	printf("%d \n", ft_printf("POINTER: |%p|", test) - 12);
	return (0);
}
*/
