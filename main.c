/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:28:16 by badriano          #+#    #+#             */
/*   Updated: 2024/08/19 13:16:42 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	new_window(t_game *game, int *size)
{
	game->window = mlx_new_window (game->init,
			size[1] * 100,
			size[0] * 100,
			"So_long");
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int		*size;
	t_game	game;

	if (argc == 2)
	{
		is_valid_map_file(argv[1]);
		fd = open(argv[1], O_RDONLY);
		map = ft_get_map(fd);
		if (!map || !map[0])
		{
			write(1, "empty file!", 11);
			free_map(map);
			close(fd);
			exit(0);
		}
		size = ft_map_size(map);
		if (ft_check_map_error(map, size) == 1)
		{
			game.map = map;
			game.init = mlx_init();
			new_window(&game, size);
			free(size);
			store_to_struct(&game);
			mlx_loop_hook(game.init, render_loop, &game);
			mlx_hook(game.window, 2, 1L << 0, move_player, &game);
			mlx_loop(game.init);
		}
	}
	return (0);
}
