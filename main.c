#include "fillit.h"

int main(int ac, char **av)
{
    int fd;
    int len;
    char buf[21 + 1];

    if (ac != 2)
    {
        printf("wrong number of input files\n");
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    ft_reader_tetri(fd);
    return (0);
}