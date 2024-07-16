/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:44:56 by badriano          #+#    #+#             */
/*   Updated: 2024/07/16 16:32:04 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

int charector_count_p(char **map, int y_count, int x_count)
{
    char map_element;
    int charector_value = 0;

    while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			map_element = map[y_count][x_count];
			 if(map_element == 'P')
				charector_value++;
			x_count++;
		}
		y_count++;
	}
    return(charector_value);
}

int charector_count_e(char **map, int y_count, int x_count)
{
    char map_element;
    int charector_value = 0;

    while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			map_element = map[y_count][x_count];
			 if(map_element == 'E')
				charector_value++;
			x_count++;
		}
		y_count++;
	}
    return(charector_value);
}

int charector_count_c(char **map, int y_count, int x_count)
{
    char map_element;
    int charector_value = 0;

    while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			map_element = map[y_count][x_count];
			 if(map_element == 'C')
				charector_value++;
			x_count++;
		}
		y_count++;
	}
    return(charector_value);
}

int	ft_number_of_elements(char **map, int *size, int y_count, int x_count)
{
    int map_p_value;
	int map_c_value;
	int map_e_value;

	map_c_value = charector_count_c(map, 0, 0);
    map_e_value = charector_count_e(map, 0, 0);
    map_p_value = charector_count_p(map, 0, 0);
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
	return (1);
	
}
int	ft_forbiden_elements(char **map, int *size, int y_count, int x_count)
{
	int	flag;

	flag = 0;
	while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			if(map[y_count][x_count] == 'C' || map[y_count][x_count] == 'P' || map[y_count][x_count] == 'E' || map[y_count][x_count] == '1' || map[y_count][x_count] == '0')
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
	flag = 1;
	if ((flag == 1) && (ft_number_of_elements(map, size, 0, 0) == 1))
		return (1);
	return (0);
}

int	ft_first_and_last_line(char **map, int *size, int y_count, int x_count)
{
	int	flag;

	flag = 0;
	while (map[0][x_count])
	{
		if(map[0][x_count] != '1')
		{
			printf("all charecters in line 1 should only be 1");
			return(0);
		}
		x_count++;
	}
	flag = 1;
	if ((flag == 1) && (ft_forbiden_elements(map, size, 0, 0) == 1))
		return (1);
	return (0);
}

int	ft_first_and_last(char **map, int *size, int y_count, int x_count)
{
	int	flag;

	flag = 0;
	while (map[y_count])
	{
		if (map[y_count][0] != '1')
		{
			printf("first char not == 1 in wall of line %d \n", y_count + 1);
			return (0);
		}
		if (map[y_count][size[1] - 1] != '1')
		{
			printf("last char not == 1 in wall of line %d \n", y_count + 1);
			return (0);
		}
		y_count++;
	}
	flag = 1;
	if ((flag == 1) && (ft_first_and_last_line(map, size, 0, 0) == 1))
		return (1);
	return (0);
}

int	ft_equal_lines(char **map, int *size, int y_count, int x_count)
{
	int	flag;

	flag = 0;
	while (map[y_count] != NULL)
	{
		x_count = 0;
		while (map[y_count][x_count] != '\0')
			x_count++;
		if (x_count < size[1])
		{
			printf("missing charectors in line %d \n", (y_count + 1));
			return (0);
		}
		else if (x_count != size[1])
		{
			printf("extra charectors in line %d \n", (y_count + 1));
			return (0);
		}
		y_count++;
	}
	flag = 1;
	if ((flag == 1) && (ft_first_and_last(map, size, 0, 0) == 1))
		return (1);
	return (0);
}

int	ft_is_rectangle(char **map, int *size, int y_count, int x_count)
{
	int	flag;

	flag = 0;
	if (size[0] == size[1])
	{
		printf("not a rectangle\n");
		return (0);
	}
	flag = 1;
	if ((flag == 1) && (ft_equal_lines(map, size, 0, 0) == 1))
		return (1);
    return (0);
}
int	ft_check_map_error(char **map, int *size)
{
	if (ft_is_rectangle(map, size, 0, 0) == 1)
		return (1); // everything is good
	return (0);     // error
}