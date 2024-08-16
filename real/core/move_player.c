/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 07:53:23 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/16 10:27:21 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
