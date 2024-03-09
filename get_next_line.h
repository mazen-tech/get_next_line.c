/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:12:53 by maabdela          #+#    #+#             */
/*   Updated: 2024/03/09 18:21:15 by maabdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


char *get_next_line(int fd);

// get_next_line_utils.c

void ft_bezero(void *str, size_t n);
size_t ft_strlen(const char *str);
char *ft_strchr(const char *str, int c);
char *ft_strjoin(const char *s1, const char *s2);


#endif
