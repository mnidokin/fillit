#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char *ft_reader_str(char *file);
char *ft_reader_move(char *str);
char *ft_aux_map(int size_m);
int *ft_reader_coord(char *str, int *coord_line);
int **ft_reader_coord_tab(char *str, int tetra_nb, int *min_map);

# define BUFF_SIZE 550

#endif