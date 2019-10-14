#include "fillit.h"

int main(int ac, char **av)
{
    char *str;
    int **coord_tab;
    int tetra_nb;
    int min_map;

    tetra_nb = (ft_strlen((str = ft_reader_str(av[1]))) + 1) / 21;
    coord_tab = ft_reader_coord_tab(str, tetra_nb, &min_map);
    return (0);
}