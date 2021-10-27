/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:42:09 by masboula          #+#    #+#             */
/*   Updated: 2020/09/13 12:42:50 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		verif_err(char *base, int lenght)
{
	int i;
	int j;

	if (!*base || lenght < 2)
		return (0);
	i = 0;
	while (i < lenght)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < lenght)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long			nb;
	unsigned int	lenght;

	lenght = ft_strlen(base);
	nb = nbr;
	if (verif_err(base, lenght) == 1)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = nb * -1;
		}
		if (nb >= lenght)
			ft_putnbr_base(nb / lenght, base);
		ft_putchar(base[nb % lenght]);
	}
}
