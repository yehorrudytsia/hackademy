#include <stdlib.h>

char *ft_strtrim(const char *s)
{
    int strlen = 0;
    size_t skipStart = 0;

    while ((s[strlen]) != '\0')
    {
        strlen++;
    }

    int flag = 0; 
    if(strlen > 0)
    {
        flag = 1; 
    }
    
    int i = 0;
    while (s[strlen - flag - i] == ' ' || s[strlen - flag - i] == '\t' || s[strlen - flag - i] == '\n')
    {
        strlen--;
    }
    i = 0;
    while (s[0 + skipStart] == ' ' || s[0 + skipStart] == '\t' || s[0 + skipStart] == '\n')
    {
        strlen--;
        skipStart++;
    }
    i = 0;


    if (strlen < 0) strlen = 0;
    char *trimmedStr = (char *) malloc(sizeof(char) * (strlen + 1));
    if (!trimmedStr)
    {
        return 0;
    }

    while (i != strlen)
    {
        trimmedStr[i] = s[i + skipStart]; // if "skipFirst" = n, then start copying from el n
        i++;
    }
    
    *(trimmedStr + i) = '\0';
    
    return trimmedStr;
}