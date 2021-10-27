/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:22:37 by masboula          #+#    #+#             */
/*   Updated: 2020/09/23 20:18:09 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	if_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	verif_error(char *base, int lenght)
{
	unsigned int	i;
	unsigned int	j;

	if (lenght < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || if_space(base[i]))
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

int	ft_index(char c, char *base, int lenght)
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_result(char *str, char *base, int lenght)
{
	int neg;
	int	result;
	int i;

	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\f')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	result = 0;
	while (ft_index(str[i], base, lenght) >= 0)
	{
		result = result * lenght + (ft_index(str[i], base, lenght));
		i++;
	}
	return (result * neg);
}

int	ft_atoi_base(char *str, char *base)
{
	int	lenght;

	lenght = 0;
	while (base[lenght] != '\0')
		lenght++;
	if (verif_error(base, lenght) == 1)
		return (ft_result(str, base, lenght));
	return (0);
}
