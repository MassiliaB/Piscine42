/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 19:06:41 by masboula          #+#    #+#             */
/*   Updated: 2020/09/15 11:33:31 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
}

int		main(int argc, char **argv)
{
	int		size;

	size = argc - 1;
	while (size > 0)
	{
		ft_putstr(argv[size]);
		write(1, "\n", 1);
		size--;
	}
	return (0);
}
