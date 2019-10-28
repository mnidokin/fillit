/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnidokin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:17:13 by mnidokin          #+#    #+#             */
/*   Updated: 2019/10/25 13:30:44 by mnidokin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_coord_line(char *str, int *coord_line)
{
	int i[2];

	i[0] = -1;
	i[1] = -1;
	while (str[++i[0]])
	{
		if (str[i[0]] == '#')
			coord_line[++i[1]] = i[0];
	}
	return (coord_line);
}

int		**ft_coord_tab(char *str, int tetra_nb, int *min_map)
{
	int		**coord_tab;
	char	*tmp;
	int		i;

	*min_map = (tetra_nb == 1 ? 2 : ft_sqrt(tetra_nb * 4));
	i = -1;
	if (!(coord_tab = (int **)malloc(sizeof(int *) * tetra_nb)))
		return (NULL);
	while (++i < tetra_nb)
	{
		if (!(coord_tab[i] = (int *)malloc(sizeof(int) * 4)))
			return (NULL);
		tmp = ft_strndup(str + i * 21, 20);
		coord_tab[i] = ft_coord_line(ft_move_coord(tmp), coord_tab[i]);
		free(tmp);
	}
	if (tetra_nb == 1 && (coord_tab[0][0] != 0 || coord_tab[0][1] != 1
				|| coord_tab[0][2] != 5 || coord_tab[0][3] != 6))
		*min_map += 1;
	i = -1;
	while (++i < tetra_nb)
		if ((coord_tab[i][3] == 3 || coord_tab[i][3] == 15)
				&& *min_map == 3 && (*min_map += 1))
			break ;
	return (coord_tab);
}

int		**ft_coord_convert(int min_map, int tetra_nb, int **coord_tab)
{
	int i[2];

	i[0] = -1;
	while (++i[0] < tetra_nb)
	{
		i[1] = -1;
		if (min_map > 4)
			while (++i[1] < 4)
				coord_tab[i[0]][i[1]] = coord_tab[i[0]][i[1]]
					+ ((coord_tab[i[0]][i[1]] / 5) * (min_map - 4));
		if (min_map == 2)
			while (++i[1] < 4)
				coord_tab[i[0]][i[1]] = coord_tab[i[0]][i[1]]
					- ((coord_tab[i[0]][i[1]] / 5) * 2);
		if (min_map == 3)
			while (++i[1] < 4)
				coord_tab[i[0]][i[1]] = coord_tab[i[0]][i[1]]
					- (coord_tab[i[0]][i[1]] / 5);
	}
	return (coord_tab);
}

int		**ft_exp(int min_map, int tetra_nb, int **coord_tab)
{
	int i[2];

	i[0] = -1;
	while (++i[0] < tetra_nb)
	{
		i[1] = -1;
		while (++i[1] < 4)
			coord_tab[i[0]][i[1]] = coord_tab[i[0]][i[1]]
				+ (coord_tab[i[0]][i[1]] / min_map);
	}
	return (coord_tab);
}
