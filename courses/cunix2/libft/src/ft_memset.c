#include <stddef.h>

void *ft_memset(void *s, int c, size_t n)
{
    size_t i = 0;
    unsigned char *startPosition = s;
    while (i != n)
    {
        *(startPosition + i) = c;
        i++;
    }

    return startPosition;
}