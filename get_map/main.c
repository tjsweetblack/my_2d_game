/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:28:16 by badriano          #+#    #+#             */
/*   Updated: 2024/07/16 16:21:07 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_map.h"

int main(void)
{
	int i = 0;
	int fd = open("./maps/map.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("failed to open file");
		return(0);
	}
	char **map = ft_get_map(fd);
	int *size = ft_map_size(map);
	i = 0;
	if ((ft_check_map_error(map, size)) == 1)
	{
		printf("map is good");
	}
	close(fd);
	return 0;
}