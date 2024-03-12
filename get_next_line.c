/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:21:58 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/09 19:04:21 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */ 
#include "get_next_line.h"


//read buffer function
static int read_buffer(int fd, char **stash, char *buffer)
{
    char    *tmp; 
    int     bytes;

    ft_bzero (buffer, BUFFER_SIZE + 1);
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
    
    /*if(tmp == NULL)
    {
        free(*stash);
        *stash = NULL;
        return (-1);
    }*/

    free(*stash);
    *stash = tmp;

    return (bytes);

}
//16  tmp is to save the readen parts of the buffer
//19 bzero to clear the buffer before starting the reading process
//20 read data and then store it into the buffer memory in BUFFER_SIZE
//if condition --> if bytes < 0 means in case of -1 error has happened
//buffer == NULL means failure of the memory allocation 
//dont forget to free(*stash) so save the data that has been accumelated and assine to NULL terminator
//if(bytes == 0) means that the read function has been reached the EOF of fd succefully
//then join the buffer for the *stash in tmp and free(*stash) agian to save the new data that has been added and prevent mem leaks 


//function of removing the result 
static void remove_result_from_stash(char **stash)
{
    char *nl; 
    char *tmp;
    size_t i;
    size_t j;

    nl = ft_strchr(*stash, '\n');
    if (!nl)
    {
        free(*stash);
        *stash = NULL;
        return ;
    }

    tmp = malloc((ft_strlen(nl)) * sizeof(char));
    i = 0;
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
//nl is a pointer to first occurance of '\n'
//tmp allocat mem for the remaning str after the new line char
//i to iterate through tmp
//j to iterate through stash and it's the first index of the str after the new line char = ft_strlen(*stash) - ft_strlen(nl) + 1 --> add 1 to deduct the new line char
//if(!nl) means that no '\n' that means all the content of the stash is one line and we will free(*stash) and return;
//if(**stash == 0) to check if the whole stash is empty now 


     

//function get_result
static void get_result(char **stash, char **result)
{
    char *nl;
    size_t len;
    size_t i;

    nl = ft_strchr(*stash, '\n');
    len = ft_strlen(*stash) - ft_strlen(nl) + 2;
    *result = (char *)malloc(len * sizeof(char));

    if(!result)
    {
        return ;
    }
    
    i = 0;
    while(i < len - 1)
    {
        (*result)[i] = (*stash)[i];
        i++;
    }
    (*result)[i] = '\0';
}
//len is the length od the final string which is located before the new line char
//*result allocat mem for the final str (before the new line char)
//if(!result) or if(*result == NULL) means that the allocation has been faild
//while i < len -1 transfere the content of the final str in the *stash to *result 
//NOTE -1 to stop the transffer before the new line char


//get_next_line
char *get_next_line(int fd)
{
    static char *stash;
    char        *buffer;
    char        *result;
    int             bytes;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    bytes = 1;
    /*if (!buffer)
    {
        return NULL;
    }*/
    while (ft_strchr(stash , '\n') == NULL && bytes > 0){
        bytes = read_buffer(fd, &stash, buffer);
    }
    free(buffer);

    if(buffer == -1)
    {
        return (NULL);
    }
    if(ft_strlen(stash) == 0){
        return (NULL);}
    
     
    get_result(&stash, &result);
    remove_result_from_stash(&stash);
    return (result);
}
// if(fd == 0 || BUFFER_SIZE <= 0) means that invalid fd or invalid buffer size return NULL
//Buffer now = allocate mem by the size of the whole BUFFER_SIZE
//while fd didn't reach the EOF keep reading usinf the read_buffer function and free(buffer) to save 
//handel error in case sth happend while reading the stream 
//and lastly if all good call the function get_result and the remove_result
