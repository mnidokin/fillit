/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:17:26 by cvassago          #+#    #+#             */
/*   Updated: 2019/10/21 16:25:36 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_space(char *str, int **coord, int i, int shift)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (coord[i][j] + shift > (int)ft_strlen(str))
			return (0);
		else if (str[coord[i][j] + shift] != '.')
			return (0);
	}
	return (1);
}

char	*ft_print(char *str, int **coord, int i, int shift)
{
	int j;

	j = -1;
	while (++j < 4)
		str[coord[i][j] + shift] = 'A' + i;
	return (str);
}

char	*ft_clean(char *str, int **coord, int i, int shift)
{
	int j;

	j = -1;
	while (++j < 4)
		str[coord[i][j] + shift] = '.';
	return (str);
}
