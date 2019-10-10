#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define BUFF_SIZE 21

typedef struct		s_tetra
{
	char			**tetra;
	char			let;
	t_size			*size;
}					t_tetra;

typedef struct		s_size
{
	int				height;
	int				width;
}					t_size;

t_list ft_reader_tetri(int fd);