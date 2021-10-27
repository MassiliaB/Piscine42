/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:00:35 by sbouhass          #+#    #+#             */
/*   Updated: 2020/09/26 14:10:31 by sbouhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_printsep(char **strs, char *sep)
{
	while (*sep)
	{
		**strs = *sep;
		sep++;
		*strs += 1;
	}
}

void	ft_concat(int size, char *dest, char **strs, char *sep)
{
	int j;
	int i;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			*dest = strs[j][i];
			dest++;
			i++;
		}
		if (j == size - 1)
			*dest = 0;
		else if (*sep)
			ft_printsep(&dest, sep);
		j++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		len;

	if (size)
	{
		len = (strs[size - 1] - *strs) + ft_strlen(strs[size - 1]) + 1;
		tab = (char *)malloc(len + ((ft_strlen(sep) - 1) * (size - 1)));
	}
	else
	{
		tab = malloc(1);
		*tab = 0;
		return (tab);
	}
	ft_concat(size, tab, strs, sep);
	return (tab);
}
