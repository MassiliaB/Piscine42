/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:23:46 by masboula          #+#    #+#             */
/*   Updated: 2020/09/19 11:42:30 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int l;

	l = max - min;
	if (min >= max)
		return (0);
	if (!(tab = (int *)malloc(sizeof(int) * l + 1)))
		return (0);
	i = 0;
	while (i < l)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
