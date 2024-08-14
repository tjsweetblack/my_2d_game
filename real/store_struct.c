/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:47 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/14 07:40:17 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

void	store_to_struct(t_game *game)
{
	int	size;

	size = 100;
	game->image.background = mlx_xpm_file_to_image(game->init, "./assets/background.xpm", &size, &size);
	game->image.exit = mlx_xpm_file_to_image(game->init, "./assets/door.xpm", &size, &size);
	game->image.wall = mlx_xpm_file_to_image(game->init, "./assets/wall.xpm", &size, &size);
	game->image.player = mlx_xpm_file_to_image(game->init, "./assets/bird.xpm", &size, &size);
	game->image.coin = mlx_xpm_file_to_image(game->init, "./assets/coin.xpm", &size, &size);
	if (game->image.player == NULL)
	{
		printf("Failed to load player image\n");
		exit(1);  // Or handle the error as appropriate
	}
	else if (game->image.background == NULL)
	{
		printf("Failed to load background image\n");
		exit (1);  // Or handle the error as appropriate
	}
	else if (game->image.exit == NULL)
	{
		printf("Failed to load exit image\n");
		exit (1);  // Or handle the error as appropriate
	}
	if (game->image.wall == NULL)
	{
		printf("Failed to load wall image\n");
		exit (1);  // Or handle the error as appropriate
	}
}
