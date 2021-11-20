#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i = 0;
    unsigned char *startDest = dest;
    unsigned const char *startSrc = src;
    while (i != n)
    {
        *(startDest + i) = *(startSrc + i);
        i++;
    }

    return dest;
}