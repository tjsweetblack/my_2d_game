/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:14:21 by badriano          #+#    #+#             */
/*   Updated: 2024/07/13 16:29:37 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include <stdlib.h>

int *ft_map_size(char **map)
{
	int y = 0;
	int x = 0;
	int i = 0;
	int *size = malloc (sizeof(int) * 3);
	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	if (!size)
	{
		printf("malloc error");
	}
	
	while(map[y] != NULL)
	{
		y++;
	}
	i = 0;
	while(map[i][x] != '\0')
	{
		x++;
	}
	size[0] = y;
	size[1] = x;
	return(size);
}