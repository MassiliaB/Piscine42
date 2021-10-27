/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:52:27 by masboula          #+#    #+#             */
/*   Updated: 2020/09/30 11:37:09 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int	*dest;
	int i;

	if (!(dest = (int *)malloc(sizeof(int) * length)))
		return (0);
	i = 0;
	while (i < length)
	{
		dest[i] = (*f)(tab[i]);
		i++;
	}
	return (dest);
}
