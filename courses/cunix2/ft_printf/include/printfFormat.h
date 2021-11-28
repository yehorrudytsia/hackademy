#ifndef FORMAT_H
#define FORMAT_H

typedef struct
{
    char argumentType;
    char flags;
    unsigned int minimumFieldWidth;
    char period;
    const char *start;
    const char *end;
} Format;

#endif