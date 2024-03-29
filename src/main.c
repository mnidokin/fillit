/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:46:44 by cvassago          #+#    #+#             */
/*   Updated: 2019/10/23 16:02:16 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	*str;
	int		**coord;
	int		i[3];

	i[2] = 0;
	if (ac != 2 || !(str = ft_reader(av[1])) || ft_errors(str) < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	i[0] = (ft_strlen(str) + 1) / 21;
	coord = ft_coord_tab(str, i[0], &i[1]);
	coord = ft_coord_convert(i[1], i[0], coord);
	free(str);
	str = ft_map_gen(i[1]);
	ft_solver(str, coord, 0, i[0]);
	ft_putchar('\n');
	i[2] = -1;
	while (++i[2] < i[0])
		free(coord[i[2]]);
	free(coord);
	free(str);
	return (0);
}
