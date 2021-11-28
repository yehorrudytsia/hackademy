#include <stdlib.h>
#include <limits.h>

#include "../include/formats.h"
#include "../include/buffer.h"

unsigned int countArgs(const char *format)
{
    unsigned int args = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format = getFormat(format)->end;
        }
        else
        {
            while (*format != '%' && *format != '\0')
            {
                format++;
            }
        }

        args++;
    }

    return args;
}


char *itoa(unsigned int num, char *str)
{
    if (num != 0)
    {
        str = (char *) itoa(num / 10, str);
        *str++ = '0' + (num % 10);
    }

    return str;
}

char *toString(int num)
{
    if (num == INT_MIN)
    {
        char *str = (char *) malloc(sizeof(char) * 12);
        str = "-2147483648";

        return str;
    }

    if (num == 0)
    {
        char *str = (char *) malloc(sizeof(char) * 2);
        *str = '0';
        *(++str) = '\0';

        return --str;
    }


    unsigned int isNegative = 0;
    if (num < 0) 
    {
        isNegative = 1;
    }

    num *= 1 - 2 * isNegative;
    unsigned int str_len = isNegative + 1;
    int tmp = num;

    while (tmp > 9)
    {
        tmp /= 10;
        str_len++;
    }

    char *str = (char *) malloc(sizeof(char) * (str_len + 1));

    if (isNegative)
    {
        *str++ = '-';
    }

    str = (char *) itoa(num, str);
    *str = '\0';
    str -= str_len;

    return str;
}