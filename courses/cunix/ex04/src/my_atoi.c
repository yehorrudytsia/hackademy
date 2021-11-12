#include <stdbool.h>

int my_atoi(const char *nptr)
{
	int number = 0;
	bool positive = true;
        
	int i = 0;

	if (nptr[i] == '-')
    	{
		positive = false;
        	i++;
    	}

	int currDigit;
    	while ('0' <= nptr[i] && nptr[i] <= '9')
    	{
		currDigit = nptr[i] - '0';
        	number = number*10 + currDigit;
        	i++;
    	}

    	if (!positive)
	{
		number *= -1;
	}

    	return number;
}
