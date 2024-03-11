#include "get_next_line.h"
#include <stddef.h>

void ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n)
    {
        *ptr++ = 0;
        n--;
    }
    
}

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

char *ft_strchr(char *str, int c)
{
    while (*str)
    {
        if(*str == (char)c){
            return (char *)str;
        }
        str++;
    }
    return (0);
    
}

char *ft_strjoin(const char *s1, const char *s2)
{
    int i;
    int j;
    char *dest;

    if(!dest)
    {
        return (0);
    }
    i = -1;
    while(s1[i++])
        dest[i] = s1[i];
    j = -1;    
    while (s2[j++])
        dest[i + j] = s2[j];
    dest[i + j] = '\0';
    return (dest);    

}