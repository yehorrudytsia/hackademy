#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "../include/printfFormat.h"
#include "../include/formats.h"
#include "../include/buffer.h"
#include "../include/utils.h"


int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    unsigned int argsAmount = countArgs(format);
    char **argsArray = (char **) malloc(sizeof(char *) * (argsAmount + 1));

    while (*format != '\0')
    {
        if (*format == '%')
        {
            Format *printfFormat = getFormat(format);

            switch (printfFormat->argumentType)
            {
                case 'i':
                    int num = va_arg(args, int);
                    *argsArray = Number(printfFormat, num);
                    break;
                case 'd':
                    num = va_arg(args, int);
                    *argsArray = Number(printfFormat, num);
                    break;
                case 'c':
                    char character = va_arg(args, int);
                    *argsArray = Char(printfFormat, character);
                    break;
                case 's':
                    const char *str = va_arg(args, const char *);
                    *argsArray = String(printfFormat, str);
                    break;
                case '%':
                    *argsArray = EscapeSequence(printfFormat);
                    break;
                default:
                    NULL;
                    break;
            }

            format = printfFormat->end;
            free(printfFormat);
        }
        else
        {
            *argsArray = getBuffer(format);

            while (*format != '%' && *format != '\0')
            {
                format++;
            }
        }

        argsArray++;
    }
    
    *argsArray = NULL;
    argsArray -= argsAmount;

    unsigned int resultingStr_len = 0;
    while (*argsArray != NULL)
    {
        resultingStr_len += bufferSize(*argsArray);
        argsArray++;
    }
    argsArray -= argsAmount;

    char *resultingStr = (char *) malloc(sizeof(char) * (resultingStr_len + 1));
    unsigned int currArgBuffer;
    while (*argsArray != NULL)
    {
        currArgBuffer = bufferSize(*argsArray);
        while ((**argsArray != '\0'))
        {
            *resultingStr++ = *(*argsArray)++;
        }

        *argsArray -= currArgBuffer;
        free(*argsArray);
        argsArray++;
    }

    argsArray -= argsAmount;
    free(argsArray);

    *resultingStr = '\0';
    resultingStr -= resultingStr_len;

    write(1, resultingStr, resultingStr_len);
    
    return resultingStr_len;
}