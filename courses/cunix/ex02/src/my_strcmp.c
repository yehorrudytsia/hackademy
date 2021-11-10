int my_strcmp(char *s1, char *s2)
{
	int diff = 0;
	while (*(s1) != '\0' && *(s2) != '\0')
	{
		if (*(s1) != *(s2))
		{
			diff += *(s1) - *(s2);	
		}

		++s1;
		++s2;
	}

	return diff;
}
