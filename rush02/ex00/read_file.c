/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:42:08 by masboula          #+#    #+#             */
/*   Updated: 2020/09/26 19:24:48 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int	main(void)
{
	char c;
	int num;
	int result;
	char buf[BUF_SIZE + 1];

	num = open("numbers.dict", O_RDONLY);
	if (num == -1)
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	result = read(num, buf, BUF_SIZE);
	buf[result] = '\0';
	write(1, "nombre de caracteres : ", 23);
	ft_putnbr(result);
	//write(1, "\nbuf : \n", 8);
	//ft_putstr(buf);
	//write(1, "\n", 1);
	close(num);
	return (0);
}
