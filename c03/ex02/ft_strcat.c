/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 10:56:43 by masboula          #+#    #+#             */
/*   Updated: 2020/09/11 13:08:02 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int l;

	l = 0;
	while (dest[l] != '\0')
		l++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[l] = src[i];
		i++;
		l++;
	}
	dest[l] = '\0';
	return (dest);
}
