/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lign.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:37:41 by masboula          #+#    #+#             */
/*   Updated: 2020/09/22 21:32:41 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int		check_two(char tab[][6], int i, int j)
{
	if (check_row_left(tab, i) == 0)
		return (0);
	if (check_row_right(tab, i) == 0)
		return (0);
	if (check_col_up(tab, j) == 0)
		return (0);
	if (check_col_down(tab, j) == 0)
		return (0);
	return (1);
}

int		ft_check_view(char tab[][6], int i, int j)
{
	if (check_double(tab, i, j) == 0)
		return (0);
	if (j == 4)
	{
		if (check_row_left(tab, i) == 0)
			return (0);
		if (check_row_right(tab, i) == 0)
			return (0);
	}
	if (i == 4)
	{
		if (check_col_up(tab, j) == 0)
			return (0);
		if (check_col_down(tab, j) == 0)
			return (0);
	}
	if (i == 4 && j == 4)
		check_two(tab, i, j);
	return (1);
}

int		ft_lign(char tab[][6], int i, int j, char n)
{
	if (i == 5)
		return (1);
	while (n < '5')
	{
		tab[i][j] = n;
	//	ft_print_tab(tab);
		if ((ft_check_view(tab, i, j) == 1)
				&& (check_double(tab, i, j) == 1))
		{
			if (j == 4)
			{
				if (ft_lign(tab, (i + 1), 1, '1') == 1)
					return (1);
			}
			else if (n == '4')
			{
				if (ft_lign(tab, i, (j + 1), '1') == 1)
					return (1);
			}
			else if (ft_lign(tab, i, (j + 1), '1') == 1)
				return (1);
		}
		tab[i][j] = ' ';
		n++;
	}
	return (0);
}
