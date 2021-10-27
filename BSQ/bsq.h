/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:34:22 by lle-briq          #+#    #+#             */
/*   Updated: 2020/09/30 21:27:11 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	**ft_split(char *str, char *charset, int *lines);
int		fill_dist(int **tab, int size[3], int obs);
int		**fill_matrice(int size[3], char **strs, char sep[3], int *cpt);
void	middle_of_sq(int **tab, int size[3], int val, int coord[3]);
void	fill_bsq(int coord[3], int **tab, int val);
void	remove_dist(int **tab, int val, int size[3]);
int		size_file(char *file);
int		all(int size[3], char **strs, char sep[3]);

#endif
