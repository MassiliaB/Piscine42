/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:59:50 by masboula          #+#    #+#             */
/*   Updated: 2020/09/19 11:57:33 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int l;

	l = max - min;
	if (min >= max)
		return (0);
	if (!(*range = (int *)malloc(sizeof(int) * l)))
		return (-1);
	i = 0;
	while (i < l)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
