# include "../includes/fractol.h"

int     *ft_stock(t_all *point)
{
    int     i;

    i = 0;
    while (point)
    {
        point->tab = (int *)ft_memalloc(sizeof(int) * i + 1));
        i++;
    }
    return(point->tab);
}