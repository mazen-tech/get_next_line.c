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
static int read_buffer(int fd, char **stash, char *buffer)
{
char *tmp;
int bytes;

ft_bzero(buffer, BUFFER_SIZE + 1);
bytes = read(fd,buffer,BUFFER_SIZE); // read from fd into buffer up to BUFFER_size

if(bytes < 0 || buffer == NULL)
{
free(*stash); //free the memory allocated to the stash buffer incase of error in reading
*stash = NULL; //then stash = NULL after freeing the memory
return (-1);
}

if(bytes == 0){
return (bytes);
}
tmp = ft_strjoin(*stash, buffer);
//to connect the newly read data from the buffer with the data lastly has been read in the stash
// and then stor the concatenated data in tmp

free(*stash);
*stash = tmp;
return (bytes);
}
