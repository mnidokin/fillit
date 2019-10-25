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

char	*ft_move_coord(char *str)
{
	str = ft_move_coord_up(str);
	str = ft_move_coord_left(str);
	return (str);
}

char	*ft_move_coord_up(char *str)
{
	int i[2];

	while (str[0] == '.' && str[1] == '.' && str[2] == '.' && str[3] == '.')
	{
		i[0] = -5;
		while ((i[0] += 5) <= 10)
		{
			i[1] = -1;
			while (++i[1] < 4)
				str[i[0] + i[1]] = str[i[0] + i[1] + 5];
		}
		i[0] = 14;
		while (++i[0] < 19)
			str[i[0]] = '.';
	}
	return (str);
}

char	*ft_move_coord_left(char *str)
{
	int i[2];

	while (str[0] == '.' && str[5] == '.' && str[10] == '.' && str[15] == '.')
	{
		i[0] = -5;
		while ((i[0] += 5) <= 15)
		{
			i[1] = -1;
			while (++i[1] < 3)
				str[i[0] + i[1]] = str[i[0] + i[1] + 1];
		}
		i[0] = -2;
		while ((i[0] += 5) < 19)
			str[i[0]] = '.';
	}
	return (str);
}
