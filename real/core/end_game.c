/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:58:01 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/16 10:07:58 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	number_of_coins(t_game *game)
{
	int	i;
	int	j;
	int	coin;

	j = 0;
	i = 0;
	coin = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if(game->map[i][j] == 'C')
				coin = 1;
			j++;
		}
		i++;
	}
	return(coin);
}

int	end_of_game(t_game *game, int x, int y)
{

	int	coin;
	int	flag;

	flag = 0;
	coin = number_of_coins(game);
	if((game->map[y][x] == 'E') && (coin == 0))
	{
		flag = 1;
		mlx_destroy_window(game->init, game->window);
		game->window = NULL;
	}
	return(flag);
}