/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:55:34 by masboula          #+#    #+#             */
/*   Updated: 2020/09/28 10:24:44 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		check_base(char *base, int lenght)
{
	unsigned int	i;
	unsigned int	j;

	if (lenght < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
				|| base[i] == '\t' || base[i] == '\r' || base[i] == '\v'
				|| base[i] == '\n' || base[i] == '\f')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *nbr, char *base_from)
{
	int neg;
	int i;
	int result;

	i = 0;
	neg = 1;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\r' || nbr[i] == '\v'
			|| nbr[i] == '\n' || nbr[i] == '\f')
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			neg = neg * -1;
		i++;
	}
	result = 0;
	while (nbr[i] && ft_index(nbr[i], base_from) >= 0)
	{
		result = ft_index(nbr[i], base_from) + result * ft_strlen(base_from);
		i++;
	}
	return (neg * result);
}
