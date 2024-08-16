/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:28:16 by badriano          #+#    #+#             */
/*   Updated: 2024/08/16 10:06:30 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		t_game	game;
		int		fd;
		char	**map;
		int		*size;

		fd = open(argv[1], O_RDONLY);
		map = ft_get_map(fd);
		size = ft_map_size(map);
		if ((ft_check_map_error(map, size)) == 1)
		{
			game.map = map;
			game.init = mlx_init();
			game.window = mlx_new_window(game.init, size[1] * 100, size[0] * 100, "So_long");
			store_to_struct(&game);
			render_map(&game);
			mlx_hook(game.window, 2, 1L<<0, close_game, &game);
			mlx_hook(game.window, 2, 1L<<0, move_player, &game);
			mlx_loop(game.init);
		}
		close(fd);
	}
	return 0;
}
