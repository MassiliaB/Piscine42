/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:22:57 by masboula          #+#    #+#             */
/*   Updated: 2020/09/10 16:11:33 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	if (str[0] >= 97 && str[0] <= 122)
		str[0] = str[0] - 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (!((str[i - 1] >= 48 && str[i - 1] <= 57)
		|| (str[i - 1] >= 65 && str[i - 1] <= 90)
		|| (str[i - 1] >= 97 && str[i - 1] <= 122)))
			if (str[i] >= 97 && str[i] <= 122)
				str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
