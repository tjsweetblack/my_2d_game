/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:38:36 by badriano          #+#    #+#             */
/*   Updated: 2024/05/30 13:37:25 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//----------store map in a matrix----------------
char	**ft_get_map(int fd);//main function
size_t	ft_strlen(char *s);
int num_Sub_Str(char const *s, char c);
char **ft_split(char *s, char c);
char *ft_strjoin(char *s1, char *s2);
//---------------find map size------------------- 
int *ft_map_size(char **map);//return matrix position[y.length][x.length]
//--------------run map veriication--------------

#endif
