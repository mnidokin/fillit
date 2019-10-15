#include "fillit.h"

int main(int ac, char **av)
{
    char *str;
    int **coord_tab;
    int tetra_nb;
    int min_map;

    if (ac !=  2)
        return (0);
    tetra_nb = (ft_strlen((str = ft_reader_str(av[1]))) + 1) / 21;
    coord_tab = ft_reader_coord_tab(str, tetra_nb, &min_map);
    for (int p = 0; p < tetra_nb; p++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d ", coord_tab[p][j]);
		printf("\n");
	}
	printf("\n\n");
    coord_tab = ft_aux_coord_convert(min_map, tetra_nb, coord_tab);
    for (int p = 0; p < tetra_nb; p++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d ", coord_tab[p][j]);
		printf("\n");
	}
	printf("\n\n");
    return (0);
}