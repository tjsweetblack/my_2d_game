/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:02:37 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/15 13:08:24 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

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
    // Base case: If the position is out of bounds or is a wall ('1') or already visited ('V'), return
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;

    // Mark this position as visited
    map[y][x] = 'V';
    //printf("v");

    // If we find a coin ('C'), increment the coins found
    if (map[y][x] == 'C')
        (*coins_found)++;

    // If we find the exit ('E'), mark it as found
    if (map[y][x] == 'E')
        (*exit_found) = 1;

    // Recursively visit the adjacent positions (up, down, left, right)
    flood_fill(map, x + 1, y, coins_found, exit_found); // right
    flood_fill(map, x - 1, y, coins_found, exit_found); // left
    flood_fill(map, x, y + 1, coins_found, exit_found); // down
    flood_fill(map, x, y - 1, coins_found, exit_found); // up
}

char **copy_map(char **original_map)
{
    int i;
    int height = 0;

    // Calculate the height of the map
    while (original_map[height])
        height++;

    // Allocate memory for the copy of the map
    char **copy = (char **)malloc((height + 1) * sizeof(char *));
    for (i = 0; i < height; i++)
        copy[i] = strdup(original_map[i]); // Duplicate each row

    copy[height] = NULL; // Terminate the map copy

    return copy;
}


int is_map_playable(char **map)
{
    int coins_found = 0;
    int exit_found = 0;
    int total_coins = 0;
    char **map_copy = copy_map(map);
	int	player_x = 0;
	int player_y = 0;

    for (int y = 0; map[y]; y++)
    {
        for (int x = 0; map[y][x]; x++)
        {
            if (map[y][x] == 'C')
                total_coins++;
        }
    }
	ft_find_player(map, &player_x, &player_y);
    printf("X: %d Y: %d", player_x, player_y);
    flood_fill(map_copy, 1, 2, &coins_found, &exit_found);

    for (int i = 0; map_copy[i]; i++)
        free(map_copy[i]);
    free(map_copy);

    if (coins_found == total_coins && exit_found)
        return 1;
    else
        return 0;
}


