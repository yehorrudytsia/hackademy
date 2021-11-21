#include <stddef.h>
#include <stdlib.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    unsigned char *startDest = dest;
    unsigned const char *startSrc = src;
    unsigned char *tmp = malloc(sizeof(unsigned char) * n);


    while (i != n)
    {
        *(tmp + i) = *(startSrc + i);
        i++;
    }
    i = 0;

    while (i != n)
    {
        *(startDest + i) = *(tmp + i);
        i++;
    }
    free(tmp);

    return dest;
}