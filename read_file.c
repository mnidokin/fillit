#include "fillit.h"

char **ft_tetra_clean(char **tab, t_size *size)
{
    char **res;
    t_size *iter;
    size_t cord;

    cord = 4;
    iter->y = 0;
    iter->i = 0;
    if (!(res = (char **)malloc(sizeof(char *) * (size->i + 1))))
    {
        ft_putstr("error");
        exit (0);
    }
    while (tab[iter->i])
    {
        cord = (ft_strchr(tab[iter->i], '#') - tab[iter->i] > cord ?
            cord : ft_strchr(tab[iter->i], '#') - tab[iter->i]);
        iter->i++;
    }
    iter->i = 0;
    while (tab[iter->i])
    {
        res[iter->y++] = ft_strsub(tab[iter->i], cord, size->y);
        iter->i++;
    }
    res[iter->y] = 0;
    return (res);
}

char **ft_tetra_mask(char **tab, t_size *size)
{
    char **res;
    t_size *iter;

    if (!(tab = (char **)malloc(sizeof(char *) * (size->i + 1))))
    {
        ft_putstr("error");
        exit (0);
    }
    iter->i = 0;
    iter->y = 0;
    while (tab[iter->i])
    {
        if (ft_strchr(tab[iter->i], '#'))
        {
            if (!(res[iter->y] = (char *)malloc(sizeof(char) * 5)))
            {
                ft_putstr("error");
                exit (0);
            }
            res[iter->y++] = ft_strdup(tab[iter->i]);
        }
        iter->i++;
    }
    res[iter->y] = 0;
    return (res);
}

t_size *ft_tetra_size(char *buf)
{
    t_size *res;
    int i;
    int wid;

    if (!(res = malloc(sizeof(t_size))))
    {
        ft_putstr("error");
        exit (0);
    }
    i = 0;
    wid = 0;
    res->y = 0;
    res->i = 0;
    while  (buf[i])
    {
        if (buf[i] == '\n')
        {
            res->i++;
            res->y = (wid > res->y ? wid : res->y);
            wid = 0;
        }
        else if (buf[i] == '#')
            wid++;
        if (((buf[i] == '\n' || buf[i] == '.') && (buf[i+3] == '#' && (buf[i+4] == '#' || buf[i+2] == '#'))) || (buf[i+6] == '#' && (buf[i+7] == '#' || buf[i+5] == '#')))
            wid++;
        i++;
    }
    res->y = (wid > res->y ? wid : res->y);
    return (res);
}

t_list *ft_tetra(char *buf, char let)
{
    t_list *res;
    t_tetra *tet;
    size_t  cord;

    if (!(tet = (t_tetra *)ft_memalloc(sizeof(t_tetra))))
    {
        ft_putstr("error");
        exit (0);
    }
    cord = ft_strchr(buf, '#') - buf;
    tet->let = let;
    tet->size = ft_tetra_size(ft_strsub(buf, cord,
        (ft_strrchr(buf, '#') - buf + 1) - cord));
    tet->mask = ft_tetra_clean((ft_tetra_mask(ft_strsplit(buf, '\n'), tet->size)),tet->size);
    return (res);
}

t_list *ft_tetra_read(int fd)
{
    t_list *res;
    char buf[BUFF_SIZE + 1];
    char let;
    int len;
    int check;

    res = NULL;
    let = 'A';
    check = 1;
    while ((len = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[len] = '\0';
        if (check == 1 && ((len != 21 && len !=20) || (check == 0 && len !=20)))
        {
            ft_putstr("error");
            exit (0);
        }
        if ((check = ft_errors(buf, len)) == -1)
        {
            ft_putstr("error");
            exit (0);
        }
        if (!res)
        {
            ft_lstadd(&res, ft_tetra(buf, let));
            let++;
        }
        else
        {
            ft_lstadd_back(&res, ft_tetra(buf, let));
            let++;
        }
    }
    return (res);
}