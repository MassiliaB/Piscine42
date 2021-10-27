/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:44:05 by masboula          #+#    #+#             */
/*   Updated: 2020/09/29 12:28:21 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		ft_putchar(str[x++]);
	}
}

int		size_file(char *file)
{
	char	buf[4096];
	int		size;
	int		fd;
	int		tot;

	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		size = read(fd, buf, 4096);
		tot = size;
		while (size)
		{
			size = read(fd, buf, 4096);
			tot += size;
		}
		close(fd);
		return (tot);
	}
	return (-1);
}
