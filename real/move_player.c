/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 07:53:23 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/15 10:10:51 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

void move_right(t_game *game, int y, int x)
{
	int flag;

	flag = end_of_game(game, x + 1, y);
	if ((game->map[y][x + 1] == 'E') && (flag == 0))
	{
		return;
	}
    end_of_game(game, x + 1, y);
    if (game->map[y][x + 1] != '1')
    {
        game->map[y][x] = '0';
        game->map[y][x + 1] = 'P';
		game->move_count++;
		printf("Moves: %d\n", game->move_count);
    }
}

void move_left(t_game *game, int y, int x)
{
	int flag;

	flag = end_of_game(game, x - 1, y);
	if ((game->map[y][x - 1] == 'E') && (flag == 0))
	{
		return;
	}
    if (game->map[y][x - 1] != '1')
    {
        game->map[y][x] = '0';
        game->map[y][x - 1] = 'P';
		game->move_count++;
		printf("Moves: %d\n", game->move_count);
    }

}

void move_down(t_game *game, int y, int x)
{
	int flag;

	flag = end_of_game(game, x, y + 1);
	if ((game->map[y + 1][x] == 'E') && (flag == 0))
	{
		return;
	}
    end_of_game(game, x, y + 1);
    if (game->map[y + 1][x] != '1')
    {
        game->map[y][x] = '0';
        game->map[y + 1][x] = 'P';
		game->move_count++;
		printf("Moves: %d\n", game->move_count);
    }
}

void move_up(t_game *game, int y, int x)
{
	int flag;

	flag = end_of_game(game, x, y - 1);
	if ((game->map[y - 1][x] == 'E') && (flag == 0))
	{
		return;
	}
    end_of_game(game, x, y - 1);
    if (game->map[y - 1][x] != '1')
    {
        game->map[y][x] = '0';
        game->map[y - 1][x] = 'P';
		game->move_count++;
		printf("Moves: %d\n", game->move_count);
    }
}

void make_moves(int key_sym, t_game *game, int x, int y)
{
    if (key_sym == XK_Up || key_sym == XK_w)
    {
        move_up(game, y, x);
    }
    else if (key_sym == XK_Down || key_sym == XK_s)
    {
        move_down(game, y, x);
    }
    else if (key_sym == XK_Left || key_sym == XK_a)
    {
        move_left(game, y, x);
    }
    else if (key_sym == XK_Right || key_sym == XK_d)
    {
        move_right(game, y, x);
    }
    else if (key_sym == XK_Escape)
    {
        mlx_destroy_window(game->init, game->window);
        game->window = NULL;
    }
}
void	find_player(t_game *game, int *x, int *y)
{
	 while (game->map[*y] != NULL)
    {
        *x = 0;
        while (game->map[*y][*x] != '\0')
        {
            if (game->map[*y][*x] == 'P')
                break;
            (*x)++;
        }
        if (game->map[*y][*x] == 'P')
            break;
        (*y)++;
    }
}

int move_player(int key_sym, void *param)
{
    int y = 0;
    int x = 0;
    t_game *game = (t_game *)param;

	find_player(game, &x, &y);
    make_moves(key_sym, game, x, y);
    render_map(game);

    return 0;
}
