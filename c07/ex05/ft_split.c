/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:22:31 by masboula          #+#    #+#             */
/*   Updated: 2020/09/24 11:35:35 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_index(char *str, char *charset, int i)
{
	int j;

	j = 0;
	while (charset[j])
	{
		if (charset[j] == str[i])
			return (1);
		j++;
	}
	return (0);
}

int		ft_count_word(char *str, char *charset)
{
	int i;
	int count_word;
	int sign;

	sign = 0;
	i = 0;
	count_word = 0;
	while (str[i] != '\0')
	{
		if (ft_index(str, charset, i) == 1)
		{
			if (sign == 1)
				count_word++;
			sign = 0;
		}
		else
			sign = 1;
		i++;
	}
	if (sign == 1)
		count_word++;
	return (count_word);
}

int		ft_one_str(char *str, char *charset, int i)
{
	int l;

	l = 0;
	while (str[i] != '\0' && ft_index(str, charset, i) == 0)
	{
		i++;
		l++;
	}
	return (l);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		k;
	int		l;
	char	**dest;

	if (!(dest = malloc(sizeof(char *) * (ft_count_word(str, charset) + 1))))
		return (0);
	i = 0;
	k = 0;
	l = 0;
	while (str[i] != '\0')
	{
		if (ft_index(str, charset, i) == 0)
		{
			dest[l] = malloc(sizeof(char) * (ft_one_str(str, charset, i) + 1));
			while (str[i] && ft_index(str, charset, i) == 0)
				dest[l][k++] = str[i++];
			dest[l][k] = '\0';
			l++;
			k = 0;
		}
		i++;
	}
	dest[l] = 0;
	return (dest);
}
