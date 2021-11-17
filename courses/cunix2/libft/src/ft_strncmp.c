#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int diff = 0;
    size_t i = 0;

    while (*(s1) != '\0' && *(s2) != '\0')
    {
        if (i > n)
        {
            return diff;
        }

        if (*(s1) != *(s2))
        {
            diff += *(s1) - *(s2);	
        }

        ++s1;
        ++s2;
        ++i;
    }

    return diff;
}

