#include <stdlib.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *substr = (char *) malloc(sizeof(char) * (len + 1));
    if (!substr)
    {
        return 0;
    }

    size_t i = 0;
    while (i != len)
    {
        *(substr + i) = *(s + i + start);
    }
    *(substr + i) = '\0';

    return substr;
}