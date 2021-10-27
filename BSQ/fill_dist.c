/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:35:24 by lle-briq          #+#    #+#             */
/*   Updated: 2020/09/30 17:49:59 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		spread(int **tab, int co[2], int size[3], int val)
{
	int		cpt;
	int		k;
	int		l;

	cpt = 0;
	k = (co[0] > 0) ? co[0] - 1 : 0;
	while (k < size[0] && k <= co[0] + 1)
	{
		l = (co[1] > 0) ? co[1] - 1 : 0;
		while (l < size[1] && l <= co[1] + 1)
		{
			if (tab[k][l] == 0)
			{
				tab[k][l] = val + 1;
				cpt++;
			}
			l++;
		}
		k++;
	}
	return (cpt);
}

int		fill_dist(int **tab, int size[3], int obs)
{
	int		filled;
	int		val;
	int		co[2];

	filled = obs;
	val = 1;
	while (filled < size[2])
	{
		co[0] = 0;
		while (co[0] < size[0])
		{
			co[1] = 0;
			while (co[1] < size[1])
			{
				if (tab[co[0]][co[1]] == val)
					filled += spread(tab, co, size, val);
				co[1]++;
			}
			co[0]++;
		}
		val++;
	}
	return (val);
}
