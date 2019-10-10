#include "fillit.h"

t_size *ft_tetra_size(char *buf)
{
    t_size *res;


    return (res);
}

t_list *ft_tetra(char *buf, char let)
{
    t_list *res;
    t_tetra *tetraminos;
    size_t  cord;

    if (!(tetraminos = (t_tetra *)ft_memalloc(sizeof(t_tetra))))
    {
        ft_putstr("error");
        exit (0);
    }
    cord = ft_strchr(buf, '#') - buf;
    tetraminos->let = let;
    tetraminos->size = ft_tetra_size(buf); 
    return (res);
}

t_list *ft_reader_tetra(int fd)
{
    t_list *res;
    char buf[BUFF_SIZE + 1];
    char let;
    ssize_t len;
    int check;

    res = NULL;
    let = 'A';

    while ((len = read(fd, buf, BUFF_SIZE)))
    {
        if (!res)
            ft_lstadd_back(&res, );
    }
    return (res);
}