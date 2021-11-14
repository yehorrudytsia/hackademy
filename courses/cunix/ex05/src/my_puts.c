#include <stdio.h>

int my_puts(const char *s)
{
	const char *next = s;
	while (*next)
	{
		if ((*next) != EOF)
		{
			putchar(*next);
			++next;
		}
	} 
		
	putchar('\n');

	return 0;
}
