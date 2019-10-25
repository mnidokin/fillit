/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:08:36 by cvassago          #+#    #+#             */
/*   Updated: 2019/10/23 18:59:41 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_value(char *line, int size)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < size - 1)
	{
		while (line[i] != '\n')
		{
			if (line[i] != '.' && line[i] != '#')
				return (-1);
			if (line[i] == '#')
				count++;
			i++;
		}
		i++;
	}
	if (count != 4)
		return (-1);
	return (1);
}

int	ft_count(char *line, int size)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < size - 1)
	{
		while (line[i] != '\n')
			i++;
		if ((i + 1) % 5)
			return (-1);
		k++;
		i++;
	}
	if (k != 4)
		return (-1);
	if ((line[size - 2] != '\n' && line[size - 1] != '\n') ||
			(line[size - 2] != '\n' && line[size - 1] != '\0'))
		return (-1);
	return (0);
}

int	ft_val_shape(char *line, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size - 1)
	{
		if (line[i] == '#')
		{
			if (line[i + 1] == '#' && (i + 1) <= 19)
				count++;
			if (line[i - 1] == '#' && (i - 1) >= 0)
				count++;
			if (line[i + 5] == '#' && (i + 5) <= 19)
				count++;
			if (line[i - 5] == '#' && (i - 5) >= 0)
				count++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (-1);
	return (0);
}

int	ft_errors(char *line)
{
	int	count;
	int	line_size;
	int	tetrim_count;

	count = 0;
	line_size = ft_strlen(line);
	if ((line_size + 1) % 21)
		return (-1);
	tetrim_count = (line_size + 1) / 21;
	while (count < tetrim_count)
	{
		if (ft_count(line, 21) < 0)
			return (-1);
		if (ft_value(line, 21) < 0)
			return (-1);
		if (ft_val_shape(line, 21) < 0)
			return (-1);
		count++;
		if (count > 26)
			return (-1);
		line = line + 21;
	}
	return (0);
}
