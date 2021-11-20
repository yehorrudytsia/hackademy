char *ft_strstr(const char *haystack, const char *needle)
{
    if (*needle == '\0')
    {
        return (char *) haystack;
    }

    int flag = 0;
    char *currNeedle; 
    char *currHaystack;

    while (*haystack != '\0')
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