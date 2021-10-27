/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:35:14 by lle-briq          #+#    #+#             */
/*   Updated: 2020/09/29 12:39:43 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		fill_line(int *line, char *str, int col, char sep[3])
{
	int		j;
	int		cpt;

	j = 0;
	cpt = 0;
	while (j < col)
	{
		if (str[j] == sep[1])
		{
			line[j] = 1;
			cpt++;
		}
		else if (j == 0 || j == col - 1)
		{
			line[j] = 2;
			cpt++;
		}
		else
			line[j] = 0;
		j++;
	}
	return (cpt);
}

int		fill_extr_line(int *line, char *str, int col, char sep[3])
{
	int		j;

	j = 0;
	while (j < col)
	{
		if (str[j] == sep[1])
			line[j] = 1;
		else
			line[j] = 2;
		j++;
	}
	return (col);
}

int		**fill_matrice(int size[3], char **strs, char sep[3], int *cpt)
{
	int		**tab;
	int		i;

	if (!(tab = malloc(size[0] * sizeof(int *))))
		return (NULL);
	i = 0;
	while (i < size[0])
	{
		if (!(tab[i] = malloc(size[1] * sizeof(int))))
			return (NULL);
		if (i == 0 || i == size[0] - 1)
			*cpt += fill_extr_line(tab[i], strs[i + 1], size[1], sep);
		else
			*cpt += fill_line(tab[i], strs[i + 1], size[1], sep);
		i++;
	}
	return (tab);
}
