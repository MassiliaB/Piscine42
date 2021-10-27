/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:35:50 by masboula          #+#    #+#             */
/*   Updated: 2020/09/23 14:48:41 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_lenght(int size, char **strs, char *sep)
{
	int i;
	int strs_size;
	int sep_size;

	if (size == 0)
		return (0);
	i = 0;
	strs_size = 0;
	while (i < size)
	{
		strs_size = strs_size + ft_strlen(strs[i]);
		i++;
	}
	sep_size = ft_strlen(sep);
	return (strs_size + (sep_size * (size - 1)));
}

char	*ft_strcat(char *src, char *dest)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0')
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		dest_size;
	char	*dest;

	dest_size = ft_lenght(size, strs, sep);
	if (!(dest = malloc(sizeof(char) * (dest_size + 1))))
		return (0);
	dest[0] = '\0';
	if (size == 0)
		return (dest);
	i = 0;
	while (i < size)
	{
		ft_strcat(strs[i], dest);
		if (i != size - 1)
			ft_strcat(sep, dest);
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}
