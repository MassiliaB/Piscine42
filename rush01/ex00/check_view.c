/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:32:51 by masboula          #+#    #+#             */
/*   Updated: 2020/09/21 19:39:14 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

int		check_double(char tab[][6], int i, int j)
{
	int x;

	x = 4;
	while (x > 0)
	{
		if (tab[x][j] == tab[i][j] && x != i)
			return (0);
		x--;
	}
	x = 4;
	while (x > 0)
	{
		if (tab[i][x] == tab[i][j] && x != j)
			return (0);
		x--;
	}
	return (1);
}

int		check_row_left(char tab[][6], int i)
{
	int		x;
	char	value_max;
	char	nb_view;

	x = 1;
	value_max = '0';
	nb_view = '0';
	while (x <= 4)
	{
		if (tab[i][x] > value_max)
		{
			value_max = tab[i][x];
			nb_view++;
		}
		x++;
	}
	if (nb_view == tab[i][0])
		return (1);
	return (0);
}

int		check_row_right(char tab[][6], int i)
{
	int		x;
	char	value_max;
	char	nb_view;

	x = 4;
	value_max = '0';
	nb_view = '0';
	while (x > 0)
	{
		if (tab[i][x] > value_max)
		{
			value_max = tab[i][x];
			nb_view++;
		}
		x--;
	}
	if (nb_view == tab[i][5])
		return (1);
	return (0);
}

int		check_col_up(char tab[][6], int j)
{
	int		x;
	char	value_max;
	char	nb_view;

	x = 1;
	nb_view = '0';
	value_max = '0';
	while (x <= 4)
	{
		if (tab[x][j] > value_max)
		{
			value_max = tab[x][j];
			nb_view++;
		}
		x++;
	}
	if (nb_view == tab[0][j])
		return (1);
	return (0);
}

int		check_col_down(char tab[][6], int j)
{
	int		x;
	char	value_max;
	char	nb_view;

	x = 4;
	value_max = '0';
	nb_view = '0';
	while (x > 0)
	{
		if (tab[x][j] > value_max)
		{
			value_max = tab[x][j];
			nb_view++;
		}
		x--;
	}
	if (nb_view == tab[5][j])
		return (1);
	return (0);
}
