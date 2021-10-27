/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:28:26 by masboula          #+#    #+#             */
/*   Updated: 2020/10/01 11:40:19 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_check_coord(char **strs, int c)
{
	int i;
	int j;
	int l;
	int first;

	first = 1;
	i = 1;
	l = 0;
	while (i <= c)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			if (first)
				l++;
		}
		first = 0;
		if (j != l)
			return (-1);
		i++;
	}
	if (i - 1 == c)
		return (j);
	return (-1);
}

int		ft_get_row(char *str, int s)
{
	int j;
	int row;

	j = 0;
	row = 0;
	while (j < s - 3 && str[j] >= '0' && str[j] <= '9')
	{
		row = row * 10 + (str[j] - '0');
		j++;
	}
	if (j != s - 3)
		return (-1);
	return (row);
}

int		ft_get_signs(char *str, char signs[3])
{
	int		j;
	int		i;
	int		s;

	i = 0;
	j = 0;
	s = 0;
	while (str[s])
		s++;
	signs[0] = str[s - 3];
	signs[1] = str[s - 2];
	signs[2] = str[s - 1];
	if (signs[0] < 32 || signs[0] > 126 || signs[1] < 32 || signs[1] > 126 ||
			signs[2] < 32 || signs[2] > 126)
		return (-1);
	return (s);
}

void	split(char *str)
{
	char	**strs;
	char	signs[3];
	int		size[3];
	int		s;
	int		lines;

	strs = ft_split(str, "\n", &lines);
	s = ft_get_signs(strs[0], signs);
	size[0] = ft_get_row(strs[0], s);
	if (s != -1 && (lines - 1 == size[0] || (lines == 3 && size[0] == 1)) &&
			size[0] > 0 && ft_check_coord(strs, size[0]) >= 0)
		size[1] = ft_check_coord(strs, size[0]);
	else
	{
		write(1, "map error\n", 10);
		return ;
	}
	size[2] = size[0] * size[1];
	all(size, strs, signs);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;
	int		size_f;

	i = 1;
	while (i < argc)
	{
		size_f = size_file(argv[i]);
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			write(1, "map error\n", 10);
		else
		{
			if (!(str = malloc((size_f + 1) * sizeof(char))))
				exit(1);
			read(fd, str, size_f);
			close(fd);
			split(str);
		}
		i++;
	}
	return (0);
}
