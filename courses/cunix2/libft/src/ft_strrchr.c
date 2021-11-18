#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
    char *ptr = NULL;
    c %= 256;
    while (*s != '\0')
    {
        if (*s == c)
        {
            ptr = (char *) s;
        }
        ++s;
    }

    return ptr;
}
