/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:26:48 by masboula          #+#    #+#             */
/*   Updated: 2020/09/15 10:37:08 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int fact;

	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	fact = 1;
	while (nb >= 1)
	{
		fact = fact * nb;
		nb--;
	}
	return (fact);
}
