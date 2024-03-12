#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef MAX_FILE_OPENED
# define MAX_FILE_OPENED 65536
#endif

//by defining the buffer size to 42 that means the buffer read 42 chars (bytes) per time
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42 
#endif

char *get_next_line(int fd);

//get_next_line_utils
void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *str);
char *ft_strchr(const char *str, int c);
char *ft_strjoin(const char *s1, const char *s2);


#endif
