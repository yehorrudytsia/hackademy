unsigned int  my_strlen(char *str)
{
	unsigned int strlen = 0;
	char next = *str;

	while (next != '\0')
	{
		next = *(++str);
		++strlen;
	}

	return strlen;

}

