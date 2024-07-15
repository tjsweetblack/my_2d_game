/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:28:16 by badriano          #+#    #+#             */
/*   Updated: 2024/07/15 17:14:46 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_map.h"
int ft_check_map_error(char **map, int *size)
{
	
	int y_size = size[0];
	int x_size = size[1];
	int y_count = 0;
	int x_count = 0;
//------------------- Rectangle validation-----------------------------
//--------------- Y ALWAYS LESS THAN X --------------------------------
	if(y_size == x_size)
	{
		printf("not a rectangle\n");
		return(0);
	}

//--------- check for equal lines (enough charectors)------------------
	while(map[y_count] != NULL)
	{
		printf("-------------------------, \n");
		printf("y_count = %d\n", y_count);
		printf("y_size = %d\n", y_size);
		printf("x_count = %d\n", x_count);
		printf("x_size = %d\n", x_size);
		printf("-------------------------, \n");
		x_count = 0;
		while (map[y_count][x_count] != '\0')
		{
			x_count++;
		}
		if(x_count < x_size)
		{
			printf("missing charectors in line %d \n", (y_count + 1));
			return(0);
		}
		else if(x_count != x_size)
		{
			printf("extra charectors in line %d \n", (y_count + 1));
			return(0);
		} 
		y_count++;
	}
//-----------------------complete---------------------------------------
	y_count = 0;
	x_count = 0;

//-----------------wall validations------------------------------------
//------------------1st and last char == 1------------------------------
	while (map[y_count])
	{
		if(map[y_count][0] != '1')
		{
			printf("first char not == 1 in wall of line %d \n", y_count + 1);
			return(0);
		}
		if(map[y_count][x_size - 1] != '1')
		{
			printf("last char %c \n", map[y_count][x_size - 1]);
			printf("last char not == 1 in wall of line %d \n", y_count + 1);
			return(0);
		}
		y_count++;
	}
//-----------------------complete---------------------------------------
//-----------------charectors in first and last charector---------------
	y_count = 0;
	x_count = 0;
	while (map[0][x_count])
	{
		if(map[0][x_count] != '1')
		{
			printf("all charecters in line 1 should only be 1");
			return(0);
		}
		x_count++;
	}
//-----------------------complete--------------------------------------
	y_count = 0;
	x_count = 0;

	while (map[y_size - 1][x_count])
	{
		if(map[y_size - 1][x_count] != '1')
		{
			printf("all charecters in last line should only be 1");
			return(0);
		}
		x_count++;
	}
//-----------------------complete---------------------------------------

	y_count = 0;
	x_count = 0;
//-----------------------forbiden element in map---------------------------------------
	char map_element;
	while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			map_element = map[y_count][x_count];
			if(map_element == 'C' || map_element == 'P' || map_element == 'E' || map_element == '1' || map_element == '0')
			{
				x_count++;
			}else
			{
				printf("forbiden element in line %d position %d the map can only conntain the following elements P,E,C,1,0", y_count + 1, x_count + 1);
				return(0);
			}

		}
		
		y_count++;
	}

//-----------------------complete---------------------------------------
//-----------------number of elements in map----------------------------
	y_count = 0;
	x_count = 0;
	int map_p_value = 0;
	int map_c_value = 0;
	int map_e_value = 0;

	while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			map_element = map[y_count][x_count];
			
			if(map_element == 'P')
			{
				map_p_value++;
			}else if(map_element == 'C')
			{
				map_c_value++;
			}else if(map_element == 'E')
			{
				map_e_value++;
			}
			x_count++;
		}
		y_count++;
	}
	if (map_p_value != 1)
	{
		printf("number of players must be one");
		return(0);
	}
	if (map_c_value < 1)
	{
		printf("number of colectibles must be above 1 add a c in the map");
		return(0);
	}
	if (map_e_value != 1)
	{
		printf("number of exits must be one");
		return(0);
	}
	
	return(1);
}
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