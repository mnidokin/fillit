#include "fillit.h"

char *ft_aux_map(int size_m)
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