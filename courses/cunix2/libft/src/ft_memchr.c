#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i = 0;
    unsigned const char *startPosition = s;
    while (i != n)
    {
        if (*(startPosition + i) == c)
        {
            return (void *) startPosition + i;
        }
        i++;
    }

    return 0;
}