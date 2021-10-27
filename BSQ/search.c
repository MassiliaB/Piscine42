/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:34:51 by lle-briq          #+#    #+#             */
/*   Updated: 2020/09/29 11:35:20 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	remove_dist(int **tab, int val, int size[3])
{
	int		i;
	int		j;

	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[1])
		{
			if (tab[i][j] != 1 && tab[i][j] != val)
				tab[i][j] = 0;
		}
	}
}

void	fill_bsq(int coord[3], int **tab, int val)
{
	int		corner_t[2];
	int		corner_b[2];
	int		i;
	int		j;

	corner_t[0] = coord[0] - val + 2;
	corner_t[1] = coord[1] - val + 2;
	corner_b[0] = coord[0] + val - 2 + coord[2];
	corner_b[1] = coord[1] + val - 2 + coord[2];
	i = corner_t[0] - 1;
	while (++i <= corner_b[0])
	{
		j = corner_t[1] - 1;
		while (++j <= corner_b[1])
			tab[i][j] = val + 1;
	}
}

void	maj_coord(int coord[3], int i, int j, int diag)
{
	coord[0] = i;
	coord[1] = j;
	coord[2] = diag;
}

void	middle_of_sq(int **tab, int size[3], int val, int coord[3])
{
	int		i;
	int		j;
	int		first;

	i = -1;
	first = 1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[1])
		{
			if (tab[i][j] == val)
			{
				if (i < size[0] - 1 && j < size[1] - 1 &&
						tab[i + 1][j + 1] == val)
					return (maj_coord(coord, i, j, 1));
				else if (first)
				{
					coord[0] = i;
					coord[1] = j;
					first = 0;
				}
			}
		}
	}
}
