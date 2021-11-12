#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

char* my_itoa(int nmb)
{
	char *str;
       	str = malloc(sizeof(nmb) * CHAR_BIT + 2);
	sprintf(str, "%d", nmb);
    	return str;
}
