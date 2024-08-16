/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:02:37 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/16 10:07:09 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_find_player(char **map, int *x, int *y)
{
	 while (map[*y] != NULL)
    {
        *x = 0;
        while (map[*y][*x] != '\0')
        {
            if (map[*y][*x] == 'P')
                break;
            (*x)++;
        }
        if (map[*y][*x] == 'P')
            break;
        (*y)++;
    }
}

void flood_fill(char **map, int x, int y, int *coins_found, int *exit_found)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
     if (map[y][x] == 'C')
        (*coins_found)++;
    if (map[y][x] == 'E')
        (*exit_found) = 1;
    map[y][x] = 'V';
    flood_fill(map, x + 1, y, coins_found, exit_found);
    flood_fill(map, x - 1, y, coins_found, exit_found);
    flood_fill(map, x, y + 1, coins_found, exit_found);
    flood_fill(map, x, y - 1, coins_found, exit_found);
}

char **copy_map(char **original_map)
{
    int i;
    int height = 0;

    i = 0;
    while (original_map[height])
        height++;
    char **copy = (char **)malloc((height + 1) * sizeof(char *));
    while (i < height)
    {
        copy[i] = strdup(original_map[i]);
        i++;
    }
    copy[height] = NULL;

    return copy;
}

int    ft_total_coins(char **map)
{
    int total_coins;
    int y;
    int x;

    total_coins = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'C')
                total_coins++;
            x++;
        }
        y++;
    }
    return(total_coins);
}

int is_map_playable(char **map)
{
    int coins_found = 0;
    int exit_found = 0;
    int total_coins = 0;
    char **map_copy = copy_map(map);
	int	player_x = 0;
	int player_y = 0;

    total_coins = ft_total_coins(map);
	ft_find_player(map, &player_x, &player_y);
    flood_fill(map_copy, player_x, player_y, &coins_found, &exit_found);
    free_map(map_copy);
    if (coins_found == total_coins && exit_found)
        return 1;
    else
        printf("Error\n");
    return 0;
}


