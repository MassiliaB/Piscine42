/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 21:41:20 by masboula          #+#    #+#             */
/*   Updated: 2020/09/20 21:59:00 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftlib.h"

void	ft_put_in_str(char **argv, char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			str[j] = argv[1][i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

int		check_param(char **argv, char *str, int argc)
{
	int i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] != ' ' && (argv[1][i] < '1' || argv[1][i] > '4'))
			return (0);
		if (argv[1][i] == ' ' && argv[1][i + 1] == ' ')
			return (0);
		if (argv[1][i] >= '1' && argv[1][i] <= '4'
				&& i != 30 && (argv[1][i + 1] != ' '))
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	ft_put_in_str(argv, str);
	return (1);
}
