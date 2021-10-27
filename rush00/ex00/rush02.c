/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:31:45 by masboula          #+#    #+#             */
/*   Updated: 2020/09/13 17:49:10 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	if (x < 1 || y < 1)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if ((j == 0 || j == x - 1) && i == 0)
				ft_putchar('A');
			else if (i == y - 1 && (j == 0 || j == x - 1))
				ft_putchar('C');
			else if (((j == 0 || j == x - 1) && (i != 0 || i != y - 1))
			|| ((i == 0 || i == y - 1) && (j != 0 || j != x - 1)))
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
