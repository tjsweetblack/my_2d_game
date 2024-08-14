/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 07:53:23 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/14 13:17:35 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

int move_player(int key_sym, void *param)
{
	int	y;
	int	x;
	t_game *game;

	y = 0;
	x = 0;
	game = (t_game *)param;


	while (game->map[y] != NULL)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{

			if (game->map[y][x] == 'P')
			{
				break;
			}

			x++;
		}
		if (game->map[y][x] == 'P')
		{
			break;
		}
		y++;
	}

	if(key_sym == XK_Up)
	{
		end_of_game(game, x, y - 1);
		if(game->map[y - 1][x] != '1')
		{
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
		}
	}
	else if(key_sym == XK_Down)
	{
		end_of_game(game, x, y + 1);
		if(game->map[y + 1][x] != '1')
		{
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
		}
	}
	else if(key_sym == XK_Left)
	{
		end_of_game(game, x - 1, y);
		if(game->map[y][x - 1] != '1')
		{
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
		}
	}
	else if(key_sym == XK_Right)
	{
		end_of_game(game, x + 1, y);
		if(game->map[y][x + 1] != '1')
		{
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
		}
	}
	else if(key_sym == XK_Escape)
	{
		printf("escape");
		mlx_destroy_window(game->init, game->window);
		game->window = NULL;
	}
	render_map(*game);
	return(0);
}
