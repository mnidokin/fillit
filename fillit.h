#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define BUFF_SIZE 21

typedef struct		s_size
{
	int				i;
	int				y;
}					t_size;

typedef struct		s_tetra
{
	char			**mask;
	char			let;
	t_size			*size;
}					t_tetra;

t_list *ft_tetra_read(int fd);
int	ft_errors(char *line, int size);