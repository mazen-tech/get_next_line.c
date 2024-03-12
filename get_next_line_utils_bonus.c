#include "get_next_line.h"
#include <stddef.h>

void ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n)
    {
        *ptr++ = '\0';
        n--;
    }
    
}

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    if(str == NULL)
    {
        return 0;
    }
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char *ft_strchr(const char *str, int c)
{
    if(str == NULL)
        return (NULL);
    while (*str)
    {
        if(*str == (char)c){
            return (char *)str;
        }
        str++;
    }
    if(*str == '\0' && c == '\0')
        return((char *)str)
    return (NULL);
    
}

char *ft_strjoin(const char *s1, const char *s2)
{
    size_t i;
    size_t len;
    char *dest;

    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    dest = (char *)malloc(len * sizeof(char));
    i = 0;
    if(!dest)
    {
        return (0);
    }
    while(s1 && *s1)
        dest[i++] = *s1;    
    while (s2 && *s2)
        dest[i++] = *s2;
    dest[i] = '\0';
    return (dest);    

}