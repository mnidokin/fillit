/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:26:05 by cvassago          #+#    #+#             */
/*   Updated: 2019/10/21 18:48:22 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_reader(char *file)
{
	char	*buf;
	char	*res;
	int		fd;
	int		ind;

	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(buf = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		close(fd);
		return (NULL);
	}
	ind = read(fd, buf, BUFF_SIZE);
	buf[ind] = '\0';
	res = ft_strdup(buf);
	free(buf);
	close(fd);
	return (res);
}
