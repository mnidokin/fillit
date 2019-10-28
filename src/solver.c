/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:27:37 by cvassago          #+#    #+#             */
/*   Updated: 2019/10/21 18:05:57 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_solver(char *str, int **coord, int i, int nb)
{
	int	j[3];

	j[0] = -1;
	j[2] = ft_map_size(str);
	if (i == nb)
	{
		ft_putstr(str);
		return (1);
	}
	while (++j[0] < (int)ft_strlen(str))
	{
		j[1] = 0;
		if (ft_space(str, coord, i, j[0]))
		{
			j[1] = 1;
			str = ft_print(str, coord, i, j[0]);
			if (ft_solver(str, coord, (i + 1), nb))
				return (1);
		}
		if (j[1])
			str = ft_clean(str, coord, i, j[0]);
	}
	if (i == 0)
		ft_solver(ft_map_gen(j[2] + 1), ft_exp(j[2] + 1, nb, coord), 0, nb);
	return (0);
}
