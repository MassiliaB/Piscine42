/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:41:37 by masboula          #+#    #+#             */
/*   Updated: 2020/10/01 11:39:31 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_index(char c, char *charset)
{
	int j;

	j = 0;
	while (charset[j])
	{
		if (charset[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int		ft_count_word(char *str, char *charset)
{
	int	n;
	int i;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] && ft_index(str[i], charset))
			i++;
		if (str[i])
			n++;
		while (str[i] && !ft_index(str[i], charset))
			i++;
	}
	return (n);
}

int		ft_one_str(char *str, char *charset, int i)
{
	int l;

	l = 0;
	while (str[i] != '\0' && ft_index(str[i], charset) == 0)
	{
		i++;
		l++;
	}
	return (l);
}

char	**ft_split(char *str, char *charset, int *lines)
{
	int		i;
	int		k;
	int		l;
	char	**dest;

	*lines = ft_count_word(str, charset);
	if (!(dest = malloc(sizeof(char *) * (*lines + 1))))
		return (0);
	i = 0;
	l = 0;
	while (str[i] != '\0')
	{
		if (ft_index(str[i], charset) == 0)
		{
			k = 0;
			dest[l] = malloc(sizeof(char) * (ft_one_str(str, charset, i) + 1));
			while (str[i] && ft_index(str[i], charset) == 0)
				dest[l][k++] = str[i++];
			dest[l][k] = '\0';
			l++;
		}
		i++;
	}
	dest[l] = 0;
	return (dest);
}
