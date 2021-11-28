#include <stdlib.h>
#include "../include/printfFormat.h"
#include "../include/utils.h"
#include "../include/buffer.h"

Format *getFormat(const char *format)
{
    Format *printfFormat = (Format *) malloc(sizeof(Format));
    printfFormat->start = format;
    printfFormat->flags = 0;
    unsigned int flagAssigned = 1;

    while (flagAssigned)
    {
        const char tmp = *(++format);
        if (tmp == '0')
        {
            printfFormat->flags = printfFormat->flags | 1;
        }
        else if (tmp == '-')
        {
            printfFormat->flags = printfFormat->flags | 2;
        }
        else if (tmp == '+')
        {
            printfFormat->flags = printfFormat->flags | 4;
        }
        else if (tmp == ' ')
        {
            printfFormat->flags = printfFormat->flags | 8;
        }
        else if (tmp == '\0')
        {
            free(printfFormat);
            exit(1);
        }
        else 
        {
            flagAssigned = 0;
        }


    }

    printfFormat->minimumFieldWidth = 0;

    while (*format >= '0' && *format <= '9')
    {
        printfFormat->minimumFieldWidth *= 10;
        printfFormat->minimumFieldWidth += *format - '0';
        format++;
    }

    printfFormat->argumentType = *format++;
    printfFormat->end = format;

    return printfFormat;
}

char *Number(Format *printfFormat, int number)
{
    char *num_str = toString(number);
    unsigned int str_len = bufferSize(num_str);
    size_t i = 0;
    

    unsigned int isSpaced = (printfFormat->flags & 8 && number >= 0) ? 1 : 0;
    unsigned int isSigned = (printfFormat->flags & 4 && number >= 0) ? 1 : 0;
    unsigned int isleftAligned = (printfFormat->flags & 2) ? 1 : 0;
    char pad = (printfFormat->flags & 1) ? '0' : ' ';

    unsigned int resultingStr_len;
    if (str_len + isSpaced > printfFormat->minimumFieldWidth || str_len + isSigned > printfFormat->minimumFieldWidth)
    {
        resultingStr_len = str_len + (isSigned || isSpaced);
    }
    else
    {
        resultingStr_len = printfFormat->minimumFieldWidth;
    }

    unsigned int num_of_pad = resultingStr_len - str_len - isSigned - isSpaced;

    char *resultingStr = (char *) malloc(sizeof(char) * (resultingStr_len + 1));
    
    if (isSigned && number >= 0)
    {
        *resultingStr++ = '+';
    }

    if (number < 0 && pad == '0')
    {
        *resultingStr++ = *num_str++;
    }

    if (!isleftAligned)
    {
        
        if (isSpaced)
        {
            *resultingStr++ = ' ';
        }

        i = 0;
        while (i != num_of_pad)
        {
            *resultingStr++ = pad;
            i++;
        }

        if (number < 0 && pad == ' ')
        {
            *resultingStr++ = *num_str++;
        }

        while (*num_str != '\0')
        {
            *resultingStr++ = *num_str++;
        }
    }
    else
    {
        if (number < 0 && pad == ' ')
        {
            *resultingStr++ = *num_str++;
        }

        if (isSpaced)
        {
            *resultingStr++ = ' ';
        }

        while (*num_str != '\0')
        {
            *resultingStr++ = *num_str++;
        }

        i = 0;
        while (i != num_of_pad)
        {
            *resultingStr++ = pad;
            i++;
        }
    }

    *resultingStr = '\0';

    return (resultingStr - resultingStr_len);
}

char *Char(Format *printfFormat, char character)
{
    unsigned int isLeftAligned = (printfFormat->flags & 2) ? 1 : 0;
    char pad = (printfFormat->flags & 1) ? '0' : ' ';
    size_t i = 0;

    unsigned int resultingStr_len;
    if (printfFormat->minimumFieldWidth >= 1)
    {
        resultingStr_len = printfFormat->minimumFieldWidth;
    }
    else
    {
        resultingStr_len = 1;
    }

    unsigned int num_of_pad = resultingStr_len - 1;
    char *resultingStr = (char *) malloc(sizeof(char) * (resultingStr_len + 1));

    if (!isLeftAligned)
    {
        while (i != num_of_pad)
        {
            *resultingStr++ = pad;
            i++;
        }
        *resultingStr++ = character;
    }
    else
    {
        *resultingStr++ = character;
        while (i != num_of_pad)
        {
            *resultingStr++ = pad;
            i++;
        }
    }
    *resultingStr = '\0';
    resultingStr -= resultingStr_len;

    return resultingStr;
}

char *String(Format *printfFormat, const char *str)
{
    size_t i = 0;
    
    if (str == NULL)
    {
        str = "(null)";
    }

    unsigned int str_len = bufferSize(str);

    unsigned int isLeftAligned = (printfFormat->flags & 2) ? 1 : 0;
    char pad = (printfFormat->flags & 1) ? '0' : ' ';

    unsigned int resultingStr_len;
    if (str_len > printfFormat->minimumFieldWidth)
    {
        resultingStr_len = str_len;
    }
    else
    {
        resultingStr_len = printfFormat->minimumFieldWidth;
    }
    

    unsigned int num_of_pad = resultingStr_len - str_len;
    char *resultingStr = (char *) malloc(sizeof(char) * (resultingStr_len + 1));

    if (!isLeftAligned)
    {
        while (i != num_of_pad)
        {
            *(resultingStr + i) = pad;
            i++;
        }
        while (*str != '\0')
        {
            *(resultingStr + i) = *str++;
            i++;
        }
    }
    else
    {
        while (*str != '\0')
        {
            *(resultingStr + i) = *str++;
            i++;
        }
        while (num_of_pad-- != 0)
        {
            *(resultingStr + i) = pad;
            i++;
        }
    }
    *(resultingStr + i) = '\0';
    
    return resultingStr;
}

char *EscapeSequence(Format *printfFormat)
{
    char *escapeSequence = (char *) malloc(sizeof(char) * 2);
    *escapeSequence = printfFormat->argumentType;
    *(escapeSequence + 1) = '\0';

    return escapeSequence;
}