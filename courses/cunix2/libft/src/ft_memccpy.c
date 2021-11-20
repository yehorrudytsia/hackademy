#include <stddef.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    size_t i = 0;
    unsigned char *startDest = dest;
    unsigned const char *startSrc = src;

    while (i != n)
    {
        if (*(startSrc + i) != c)
        {
            *(startDest + i) = *(startSrc + i);
            i++;
        }
        else 
        {
            return (dest + i + 1);
        }
    }

    return 0;
}