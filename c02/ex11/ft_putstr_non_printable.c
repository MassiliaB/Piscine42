/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:31:35 by masboula          #+#    #+#             */
/*   Updated: 2020/09/10 16:09:16 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hexa(char c)
{
	char *hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[(unsigned char)c / 16], 1);
	write(1, &hexa[(unsigned char)c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			write(1, "\\", 1);
			ft_hexa(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
