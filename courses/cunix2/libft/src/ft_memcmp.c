#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    int diff = 0;
    size_t i = 0;
    unsigned const char *startS1 = s1;
    unsigned const char *startS2 = s2;

    while (i != n)
    {
        diff += *(startS1 + i) - *(startS2 + i);
        i++;
    }

    return diff;
}