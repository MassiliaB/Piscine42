/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:41:58 by masboula          #+#    #+#             */
/*   Updated: 2020/09/30 17:49:01 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int long nb)
{
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	print_result(int (*ft)(int, int), char *first, char *second, int j)
{
	int f;
	int s;

	f = ft_atoi(first);
	s = ft_atoi(second);
	if (j == 1 && s == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	if (j == 2 && s == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	putnbr((*ft)(f, s));
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			print_result(&add, argv[1], argv[3], 0);
		else if (argv[2][0] == '-')
			print_result(&sub, argv[1], argv[3], 0);
		else if (argv[2][0] == '*')
			print_result(&mltiply, argv[1], argv[3], 0);
		else if (argv[2][0] == '/')
			print_result(&divd, argv[1], argv[3], 1);
		else if (argv[2][0] == '%')
			print_result(&modulo, argv[1], argv[3], 2);
		else
			write(1, "0\n", 2);
	}
	return (0);
}
