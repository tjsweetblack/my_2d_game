/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:58:01 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/15 09:59:05 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

int	close_game(int Key_sym, void *param)
{
	t_game	*game;

	game = (t_game *)param;

	if(Key_sym == XK_Escape)
	{
		mlx_destroy_window(game->init, game->window);
		game->window = NULL;
	}
	return(0);
}

int	end_of_game(t_game *game, int x, int y)
{
	char	**map;
	int	i;
	int	j;
	int	coin = 0;
	int	flag;

	j = 0;
	i = 0;
	flag = 0;
	map = game->map;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
			{
				coin = 1;
			}
			j++;
		}
		i++;
	}
	if((map[y][x] == 'E') && (coin == 0))
	{
		flag = 1;
		mlx_destroy_window(game->init, game->window);
		game->window = NULL;
	}
	return(flag);
}
