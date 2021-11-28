#ifndef RESOLVERS_H
#define RESOLVERS_H

#include "printfFormat.h"

Format *getFormat(const char *format);
char *Number(Format *formatType, int num);
char *Char(Format *formatType, char character);
char *String(Format *formatType, const char *str);
char *EscapeSequence(Format *formatType);

#endif