/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:40:05 by cvassago          #+#    #+#             */
/*   Updated: 2019/10/21 16:45:25 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** include
*/

# include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** define
*/

# define BUFF_SIZE 550

/*
** reader.c
*/

char	*ft_reader(char *file);

/*
** map.c
*/

int		ft_map_size(char *str);
char	*ft_map_gen(int size_m);

/*
** coord.c
*/

int		**ft_coord_tab(char *str, int tetra_nb, int *min_map);
int		**ft_coord_convert(int min_map, int tetra_nb, int **coord_tab);
int		**ft_coord_exp(int min_map, int tetra_nb, int **coord_tab);

/*
** coord_move.c
*/

char	*ft_move_coord(char *str);
char	*ft_move_coord_up(char *str);
char	*ft_move_coord_left(char *str);

/*
** map_oper.c
*/

char	*ft_print(char *str, int **coord, int i, int shift);
int		ft_space(char *str_map, int **coord, int i, int shift);
char	*ft_clean(char *str, int **coord, int i, int shift);

/*
** solver.c
*/

int		ft_solver(char *str, int **coord, int i, int nb);

/*
** errors.c
*/

int		ft_value(char *line, int size);
int		ft_count(char *line, int size);
int		ft_val_shape(char *line, int size);
int		ft_errors(char *line);

#endif
