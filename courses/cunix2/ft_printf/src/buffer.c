#include <stdlib.h>

unsigned int bufferSize(char *buffer)
{
    unsigned int len = 0;
    while (*buffer != '\0')
    {
        buffer++;
        len++;
    }
    
    return len;
}

char *getBuffer(const char *format)
{
    unsigned int buff_len = 0;
    size_t i = 0;

    while (*format != '%' && *format != '\0')
    {
        format++;
        buff_len++;
    }
    format -= buff_len;

    char *buffer = (char *) malloc(sizeof(char) * (buff_len + 1));
    while (*(format + i) != '%' && *(format + i) != '\0')
    {
        *(buffer + i) = *(format + i);
        i++;
    }

    *(buffer + i) = '\0';

    return buffer;
}