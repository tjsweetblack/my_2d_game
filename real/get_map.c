/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:35:21 by badriano          #+#    #+#             */
/*   Updated: 2024/07/15 17:54:35 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

char *left_str(char *chars_read, char *buf, int fd)
{
    int bytes_read = 1;

    while (bytes_read != 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[bytes_read] = '\0'; // Properly null-terminate the buffer
        chars_read = ft_strjoin(chars_read, buf);
        if (bytes_read == 0)
            break;
    }
    return chars_read;
}

char **ft_get_map(int fd)
{
    char buf[BUFFER_SIZE + 1];
    char *chars_read = NULL;
    char **matrix;
    //printf("done");
    //buf[0] = '\0';
     if (fd == 0)
     {
        printf("empty file!");
        return (NULL);
     }
    chars_read = left_str(chars_read, buf, fd);
    if (!chars_read || chars_read[0] == '\0')
        return (NULL);
    matrix = ft_split(chars_read, '\n');

    //line = ft_new_line(chars_read);
    //chars_read = ft_new_left_str(chars_read);
    return (matrix);
}