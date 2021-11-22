#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len1 = 0;
    while (*(s1 + len1) != '\0')
    {
        len1++;
    }

    size_t len2 = 0;
    while (*(s2 + len2) != '\0')
    {
        len2++;
    }

    char *newStr = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
    if (!newStr)
    {
        return 0;
    }

    size_t i;
    for (i = 0; s1[i] != '\0'; i++)
    {   
        newStr[i] = s1[i];
    }
    for (i = len1; s2[i - len1] != '\0'; i++)
    {   
        newStr[i] = s2[i - len1];
    }
    newStr[i] = '\0';
    
    return newStr;
}