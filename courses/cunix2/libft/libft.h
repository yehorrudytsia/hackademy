#ifndef   LIBFT_H_
#define   LIBFT_H_

#include <stddef.h>
#include <stdlib.h>


void ft_bzero(void *s, size_t n);
char *ft_strdup(const char *s);
int ft_strncmp(const char *str1, const char *str2, size_t n);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isascii(int c);



div_t ft_div(int numer, int denom);
char *ft_strstr(const char *haystack, const char *needle);
char *ft_strnstr(const char *haystack, const char *needle, size_t n);
void *ft_memset(void *s, int c, size_t n);

#endif
