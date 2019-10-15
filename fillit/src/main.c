#include "fillit.h"

int main(int ac, char **av)
{
    char *str;
    int **coord_tab;
    int tetra_nb;
    int min_map;

    if (ac !=  2)
        return (0);
    tetra_nb = (ft_strlen((str = ft_reader_str(av[1]))) + 1) / 21; // читаем файл в однну строку str и считаю количество элементов tetra_nb
    coord_tab = ft_reader_coord_tab(str, tetra_nb, &min_map); // записываем координаты элементов, смещенных в левый верхний угол относительно карты 4х4, считаем минимальный размер карты
    coord_tab = ft_aux_coord_convert(min_map, tetra_nb, coord_tab); // конвертируем координаты для карты размером min_map
    return (0);
}
