/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:14:20 by cvassago          #+#    #+#             */
/*   Updated: 2019/10/21 16:16:55 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_map_gen(int size_m)
{
	char	*map;
	int		i[2];

	i[0] = -1;
	i[1] = size_m * (size_m + 1);
	if (!(map = (char *)malloc(sizeof(char) * i[1] + 1)))
		return (NULL);
	while (++i[0] < i[1] - 1)
	{
		if ((i[0] + 1) % (size_m + 1) == 0)
			map[i[0]] = '\n';
		else
			map[i[0]] = '.';
	}
	map[i[0]] = '\0';
	return (map);
}

int		ft_map_size(char *str)
{
	int	i;

	i = -1;
	while (str[++i] == '.')
		;
	return (i);
}
