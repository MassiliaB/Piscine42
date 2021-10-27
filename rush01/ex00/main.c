/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:37:59 by masboula          #+#    #+#             */
/*   Updated: 2020/09/22 21:48:59 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ftlib.h"

void	create_str(char *str, char tab[][6])
{
	int i_tab;
	int i_str;

	i_tab = 1;
	i_str = 0;
	while (i_tab < 5)
		tab[0][i_tab++] = str[i_str++];
	i_tab = 1;
	while (i_tab < 5)
		tab[5][i_tab++] = str[i_str++];
	i_tab = 1;
	while (i_tab < 5)
		tab[i_tab++][0] = str[i_str++];
	i_tab = 1;
	while (i_tab < 5)
		tab[i_tab++][5] = str[i_str++];
}

void	ft_init(char tab[][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			tab[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	ft_print_tab(char tab[][6])
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	*str;
	int		j;
	int		i;
	char	n;
	char	tab[6][6];

	j = 1;
	i = 1;
	n = '1';
	if (!(str = (char *)malloc(sizeof(char) * 16 + 1)))
		return (0);
	if (check_param(argv, str, argc) == 0)
		write(1, "Error\n", 6);
	else
	{
		ft_init(tab);
		create_str(str, tab);
		if (ft_lign(tab, i, j, n) == 1)
			ft_print_tab(tab);
		else
			write(1, "Error else\n", 11);
	}
	free(str);
	return (0);
}
