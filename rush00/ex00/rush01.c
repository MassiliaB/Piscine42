/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:53:25 by masboula          #+#    #+#             */
/*   Updated: 2020/09/13 17:51:06 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar();

void	ft_condition(int x, int y, int i, int j)
{
	if (j == 0 && i == 0)
		ft_putchar('/');
	else if ((j == x - 1 && i == 0) || (j == 0 && i == y - 1))
		ft_putchar('\\');
	else if (i == y - 1 && j == x - 1)
		ft_putchar('/');
	else if (((j == 0 || j == x - 1) && (i != 0 || i != y - 1))
			|| ((i == 0 || i == y - 1) && (j != 0 || j != x - 1)))
		ft_putchar('*');
	else
		ft_putchar(' ');
}

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
			ft_condition(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
