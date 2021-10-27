/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 10:56:40 by masboula          #+#    #+#             */
/*   Updated: 2020/09/09 11:10:20 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnb(int i, int j)
{
	ft_putchar(i / 10 + '0');
	ft_putchar(i % 10 + '0');
	write(1, " ", 1);
	ft_putchar(j / 10 + '0');
	ft_putchar(j % 10 + '0');
}

void	go_on(int i)
{
	if (i != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putnb(i, j);
			go_on(i);
			j++;
		}
		i++;
	}
}
