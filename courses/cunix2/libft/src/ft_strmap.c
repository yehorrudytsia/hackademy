#include <stdlib.h>

char *ft_strmap(char const *s, char (*f)(char))
{
    size_t strlen = 0;
    while (*(s++) != '\0')
    {
        strlen++;
    }

    char *mappedStr = (char *) malloc(sizeof(char) * (strlen + 1));

    size_t i;
    for (i = 0; s[i] != '\0'; i++)
    {   
        mappedStr[i] = f(s[i]);
    }
    mappedStr[i] = '\0';
    
    return mappedStr;
}