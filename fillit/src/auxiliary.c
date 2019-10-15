#include "fillit.h"

char *ft_aux_map_gen(int size_m)
{
    char *map;
    int i[2];

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

char *ft_aux_move(char *str)
{
    int i[2];

    while (str[0] == '.' && str[1] == '.' && str[2] == '.' && str[3] == '.')
    {
        i[0] = -5;
        while ((i[0] += 5) <= 10)
        {
            i[1] = -1;
            while (++i[1] < 4)
                str[i[0] + i[1]] = str[i[0] + i[1] + 5];
        }
        i[0] = 14;
        while (++i[0] < 19)
            str[i[0]] = '.';
    }
    while (str[0] == '.' && str[5] == '.' && str[10] == '.' && str[15] == '.')
    {
        i[0] = -5;
        while ((i[0] += 5) <= 15)
        {
            i[1] = -1;
            while (++i[1] < 3)
                str[i[0] + i[1]] = str[i[0] + i[1] + 1];
        }
        i[0] = -2;
        while ((i[0] += 5) < 19)
            str[i[0]] = '.';
    }
    return(str);
}

int **ft_aux_coord_convert(int min_map, int tetra_nb, int **coord_tab)
{
    int i[2];

    i[0] = -1;
    while (++i[0] < tetra_nb)
    {
        i[1] = -1;
        if (min_map > 4)
        {
            while (++i[1] < 4)
                coord_tab[i[0]][i[1]] = coord_tab[i[0]][i[1]]
                + ((coord_tab[i[0]][i[1]] / 5) * (min_map - 4));
        }
        if (min_map == 2)
        {
            while (++i[1] < 4)
                coord_tab[i[0]][i[1]] = coord_tab[i[0]][i[1]] - ((coord_tab[i[0]][i[1]]/5) * 2);
        }
        if (min_map == 3)
        {
            while (++i[1] < 4)
                coord_tab[i[0]][i[1]] = coord_tab[i[0]][i[1]] - (coord_tab[i[0]][i[1]] / 5);
        }
    }
    return (coord_tab);
}