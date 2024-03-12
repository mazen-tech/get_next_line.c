#include "get_next_line.h"

//read buffer function
static int read_buffer(int fd, char **stash, char *buffer)
{
    char    *tmp; 
    int     bytes;

    ft_bzero (buffer,BUFFER_SIZE + 1);
    bytes = read (fd, buffer, BUFFER_SIZE);
    if (bytes < 0 || buffer == NULL)
    { 
        free(*stash); 
        *stash = NULL; 
        return (-1);
    }

    if (bytes == 0)
    {
        return (0); 
    }

    tmp = ft_strjoin(*stash, buffer);
    
    if(tmp == NULL)
    {
        free(*stash);
        *stash = NULL;
        return (-1);
    }

    free(*stash);
    *stash = tmp;

    return (bytes);

}
 
static void remove_result_from_stash(char **stash)
{
    char *nl; 
    char *tmp;
    size_t i = 0;
    size_t j;

    nl = ft_strchr(*stash, '\n');
    if (!nl)
    {
        free(*stash);
        *stash = '\0';
        return;
    }

    tmp = malloc(ft_strlen(nl) * sizeof(char));
    j = ft_strlen(*stash) - ft_strlen(nl) + 1;
    while (j < ft_strlen(*stash))
    {
        tmp[i++] = (*stash)[j++];
    }

    tmp[i] = '\0';
    free(*stash);
    *stash = tmp;

    if (**stash == 0)
    {
        free(*stash);
        *stash = NULL;
    }

}

static void get_result(char **stash, char **result)
{
    char *nl;
    size_t len;
    size_t i = 0;

    nl = ft_strchr(*stash, '\n');
    len = ft_strlen(*stash) - ft_strlen(nl) + 2;
    *result = malloc(len * sizeof(char));

    if(!result)
    {
        return ;
    }

    while(i < len -1)
    {
        (*result)[i] = (*stash)[i];
        i++;
    }
    (*result)[i] = '\0';
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *buffer;
    char        *result;
    int             bytes = 1;

    if(fd == 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    while (ft_strchr(stash , '\n') == NULL && bytes > 0){
        bytes = read_buffer(fd, &stash, buffer);
    }
    free(buffer);

    if(bytes == -1 || ft_strlen(stash) == 0)
        return (NULL);
    

    get_result(&stash, &result);
    remove_result_from_stash(&stash);
    return (result);
}

