/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masboula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:35:41 by masboula          #+#    #+#             */
/*   Updated: 2020/09/20 21:54:51 by masboula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FTLIB_H
# define _FTLIB_H

# include <unistd.h>
# include <stdlib.h>

int		main(int argc, char **argv);
void	ft_print_tab(char tab[][6]);
void	ft_init(char tab[][6]);
int		check_param(char **argv, char *str, int argc);
void	ft_put_in_str(char **argv, char *str);
void	create_str(char *str, char tab[][6]);
int		ft_lign(char tab[][6], int i, int j, char n);
int		ft_check_view(char tab[][6], int i, int j);
int		check_two(char tab[][6], int i, int j);
int		check_col_down(char tab[][6], int j);
int		check_col_up(char tab[][6], int j);
int		check_row_right(char tab[][6], int i);
int		check_row_left(char tab[][6], int i);
int		check_double(char tab[][6], int i, int j);

#endif
