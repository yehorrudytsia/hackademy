#include <stdlib.h>

div_t ft_div(int numer, int denom)
{
    int quot = numer / denom;
    int rem = numer % denom;

    div_t result =
    {
        quot, rem
    };

    return result;
}