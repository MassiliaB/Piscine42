/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:16:57 by masboula          #+#    #+#             */
/*   Updated: 2020/09/27 19:55:13 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft.h"

char	*ft_put_in_nbr(char *str)
{
	int i;
	int j;
	char *nbr;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nbr[j] = str[i];
			j++;
		}
		i++;
	}
	nbr[j] = '\0';
	return (nbr);
}

int		main(int argc, char **argv)
{
	char *nbr;
	int lenght;

	if (argc > 3)
		return (0);

	ft_read_file();
	lenght = ft_strlen(argv[1]);
	if (!(nbr = (char *)malloc(sizeof(char) * (lenght + 1))))
		return (0);
	nbr = ft_put_in_nbr(argv[1]);
	return (0);
}	
