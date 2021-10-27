/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:40:09 by masboula          #+#    #+#             */
/*   Updated: 2020/09/28 10:42:01 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		check_base(char *base, int lenght);
int		ft_atoi_base(char *nbr, char *base_from);
int		ft_strlen(char *str);

char	*ft_putnbr_base(char *base_to, int size, long nb, char *nb_final)
{
	int sign;

	sign = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		sign = 0;
	}
	while (nb >= ft_strlen(base_to))
	{
		nb_final[size] = base_to[nb % ft_strlen(base_to)];
		nb = nb / ft_strlen(base_to);
		size--;
	}
	if (nb < ft_strlen(base_to))
		nb_final[size] = base_to[nb];
	if (sign == 0)
		nb_final[size - 1] = '-';
	return (nb_final);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int		nb;
	long int		copy;
	char			*nb_final;
	int				size;

	if ((check_base(base_from, ft_strlen(base_from)) == 0)
			|| check_base(base_to, ft_strlen(base_to)) == 0)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	copy = nb;
	size = 1;
	if (copy < 0 && size++)
		copy = copy * (-1);
	while (copy >= ft_strlen(base_to))
	{
		copy = copy / ft_strlen(base_to);
		size++;
	}
	if (!(nb_final = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_putnbr_base(base_to, size - 1, nb, nb_final);
	nb_final[size] = '\0';
	return (nb_final);
}
