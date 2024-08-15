/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:28:16 by badriano          #+#    #+#             */
/*   Updated: 2024/08/15 09:41:47 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_map.h"

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		t_game	game;

		int fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("failed to open file");
			return(0);
		}
		char **map = ft_get_map(fd);
		int *size = ft_map_size(map);
		if ((ft_check_map_error(map, size)) == 1)
		{
			game.map = map;
			game.init = mlx_init();
			game.window = mlx_new_window(game.init, size[1] * 100, size[0] * 100, "So_long");

			store_to_struct(&game);
			render_map(&game);
			mlx_loop_hook(game.init, render_map, &game);
			mlx_hook(game.window, 2, 1L<<0, close_game, &game);
			mlx_hook(game.window, 2, 1L<<0, move_player, &game);
			mlx_loop(game.init);
		}
		close(fd);
	}
	return 0;
}
