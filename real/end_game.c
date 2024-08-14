/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:58:01 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/14 13:21:21 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

int	close_game(int Key_sym, void *param)
{
	t_game	*game;

	game = (t_game *)param;

	if(Key_sym == XK_Escape)
	{
		printf("escape");
		mlx_destroy_window(game->init, game->window);
		game->window = NULL;
	}
	return(0);
}

void	end_of_game(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int coin;
	char	**map;

	j = 0;
	i = 0;
	map = game->map;
	while(map[i])
	{
		while(map[i][j])
		{
			if(map[i][j] == 'C')
			{
				coin++;
			}
			j++;
		}
		i++;
	}
	if((map[y][x] == 'E') && (coin == 0))
	{
		mlx_destroy_window(game->init, game->window);
		game->window = NULL;
	}
}
