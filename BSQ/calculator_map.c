/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:34:58 by lle-briq          #+#    #+#             */
/*   Updated: 2020/09/30 17:44:54 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_final(int size[3], int **tab, char sep[3])
{
	int		i;
	int		j;
	char	*line;

	if (!(line = malloc(size[1] * sizeof(char))))
		return ;
	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[1])
		{
			if (tab[i][j] == 0)
				line[j] = sep[0];
			else if (tab[i][j] == 1)
				line[j] = sep[1];
			else
				line[j] = sep[2];
		}
		write(1, line, size[1]);
		write(1, "\n", 1);
	}
}

int		all(int size[3], char **strs, char sep[3])
{
	int		cpt;
	int		max;
	int		**tab;
	int		coord[3];

	cpt = 0;
	tab = fill_matrice(size, strs, sep, &cpt);
	max = fill_dist(tab, size, cpt);
	coord[2] = 0;
	middle_of_sq(tab, size, max, coord);
	fill_bsq(coord, tab, max);
	remove_dist(tab, max + 1, size);
	print_final(size, tab, sep);
	return (0);
}
