#include <stddef.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t n)
{
    if (*needle == '\0')
    {
        return (char *) haystack;
    }

    int flag = 0;
    char *currNeedle; 
    char *currHaystack;
    char *terminated = (char *)haystack + n;

    while (*haystack != '\0' && haystack != terminated)
    {
        currNeedle = (char *) needle;
        currHaystack = (char *) haystack;
        char *currentPosition = currHaystack;

        while (*currNeedle != '\0')
        {
            if (*currHaystack++ == *currNeedle++)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            return currentPosition;
        }

        haystack++;
    }

    return 0;
}