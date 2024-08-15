/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:47 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/15 09:22:59 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

void	store_to_struct(t_game *game)
{
	int	size;

	size = 100;
	game->move_count = 0;
	game->image.background = mlx_xpm_file_to_image(game->init, "./assets/background.xpm", &size, &size);
	game->image.exit = mlx_xpm_file_to_image(game->init, "./assets/door.xpm", &size, &size);
	game->image.wall = mlx_xpm_file_to_image(game->init, "./assets/wall.xpm", &size, &size);
	game->image.player = mlx_xpm_file_to_image(game->init, "./assets/bird.xpm", &size, &size);
	game->image.coin = mlx_xpm_file_to_image(game->init, "./assets/coin.xpm", &size, &size);
}
