/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:11:52 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 15:29:46 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_resize(t_data *data)
{
	render_game(data);
	return (0);
}

int key_change(int keysym)
{
	int key;
	
	key = 0;
	if(keysym == XK_Left)
	{
		key = 97;
	}else if(keysym == XK_Up)
	{
		key = 119;
	}else if(keysym == XK_Right)
	{
		key = 100;
	}else if(keysym == XK_Down)
	{
		key = 115;
	}
	return(key);
}

int	key_handler(int keysym, t_data *data)
{
	if(keysym == XK_Left || keysym == XK_Up || keysym == XK_Right || keysym == XK_Down)
	{
		keysym = key_change(keysym);
	}

	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	else if (ft_strchr("wasd", keysym))
	{
		move_the_player(data, keysym);
	}
	return (0);
}

int	realeasekey_handler(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}
