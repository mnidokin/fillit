#include "fillit.h"

char *ft_reader_str(char *file)
{
    char *buf;
    char *res;
    int fd;
    int ind;

    if (!(fd = open(file, O_RDONLY)))
    {
        ft_putstr("file open error\n");
        return (NULL);
    }
    if (!(buf = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
    {
        ft_putstr("memalloc error\n");
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

int *ft_reader_coord(char *str, int *coord_line)
{
    int i[2];

    i[0] = -1;
    i[1] = -1;
    while (str[++i[0]])
    {
        if (str[i[0]] == '#')
            coord_line[++i[1]] = i[0];
    }
    return (coord_line);
}

int **ft_reader_coord_tab(char *str, int tetra_nb, int *min_map)
{
    int **coord_tab;
    char *tmp;
    int i;

    *min_map = (tetra_nb == 1 ? 2 : ft_sqrt(tetra_nb * 4));
    i = -1;
    if (!(coord_tab = (int **)malloc(sizeof(int *) * tetra_nb)))
        return (NULL);
    while (++i < tetra_nb)
    {
        if (!(coord_tab[i] = (int *)malloc(sizeof(int) * 4)))
            return (NULL);
        tmp = ft_strndup(str + i * 21, 20);
        coord_tab[i] = ft_reader_coord(ft_aux_move(tmp), coord_tab[i]);
        free(tmp);
    }
    if (tetra_nb == 1 && (coord_tab[0][0] != 0 || coord_tab[0][1] != 1
				|| coord_tab[0][2] != 5 || coord_tab[0][3] != 6))
		*min_map += 1;
    i = -1;
    while (++i < tetra_nb)
        if ((coord_tab[i][3] == 3 || coord_tab[i][3] == 15) && *min_map == 3 && (*min_map += 1))
            break ;
    return(coord_tab);
}