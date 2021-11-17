#include <stdlib.h>

char *ft_strdup(const char *s)
{
    int strlen = 1;
    while (*s++ != '\0')
    {
        strlen++;
    }

    char *s2 = (char *) malloc((size_t) strlen);
    char *ptr = s2;

    for (int i = 0; i < strlen; ++i)
    {
        s2[i] = s[i];
    }
    s2[strlen] = '\0';

    return ptr; 
}
