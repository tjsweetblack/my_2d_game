/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:14 by msanjuan          #+#    #+#             */
/*   Updated: 2024/07/23 13:07:53 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/get_next_line.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (check_extension_bonus(argv[1]) == FAILURE)
			msg_error_bonus(ERRBER, &data);
		create_map_bonus(argv[1], &data);
		init_map_bonus(&data);
		map_check_bonus(&data);
		init_players_bonus(&data);
		init_window_bonus(&data);
		init_images_bonus(&data);
		render_game_bonus(&data);
		loop_images_bonus(data);
		destroy_images_bonus(data);
		free(data.mlx);
		if (data.map.map)
			ft_free_bonus(data.map.map);
	}
}
