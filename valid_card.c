#include "fillit.h"

int	ft_value(char *line, int size)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		while (line[i] != '\n')
		{
			if (line[i] != '.' || line[i] != '#')
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
	while (i < size)
	{
		while (line[i] != '\n')
			i++;
		if ((i + 1) % 5)
			return (-1);
		k++;
	}
	if (k != 5)
		return (-1);
	if (line[size - 2] != '\n' && line[size - 1] != '\n' && line[size] != '\0')
		return (-1);
	return (0);
}

int	ft_val_shape(char *line, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size && count < 4)
	{
		while (line[i] != '\0' && (line[i] == '.' || line[i] == '\n'))
			i++;
		count++;
		if (i < 14)
		{
			if (line[i + 1] != '#' || line[i + 5] != '#')
				return (-1);
		}
		else if (i > 14)
		{
			if (line[i + 1] != '#')
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_errors(char *line, int size)
{
	int	count;
	
	count = 0;
	if (ft_strlen(line) != size)
		return (-1);
	if (ft_count(line, size) < 0)
		return (-1);
	if (ft_value(line, size) < 0)
		return (-1);
	if (ft_val_shape(line, size) < 0)
		return (-1);
	return (0);
}