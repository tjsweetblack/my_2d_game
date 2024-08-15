/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badriano <badriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:38:36 by badriano          #+#    #+#             */
/*   Updated: 2024/05/30 13:37:25 by badriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

# include <ctype.h>
# include <errno.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./minilibx_linux/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*typedef struct t_coin
{
	int			total_coin;
}				t_coin;*/


typedef struct t_image
{
	void		*player;
	void		*wall;
	void		*background;
	void		*exit;
	void		*coin;
}				t_image;

typedef struct t_game
{
	void		*init;
	void		*window;
	char		**map;
	int			move_count;
	//t_coin		coin;
	t_image		image;
	//t_player	player;
	//t_coin	coin;
	//t_wall	wall;
}				t_game;

/*
typedef struct t_map
{
	void		*init;
	void		*window;
}				t_map;*/


/*typedef struct t_player
{
	void		*init;
	void		*window;
}				t_player;

typedef struct t_wall
{
	void		*init;
	void		*window;
}				t_wall;




*/
//----------store map in a matrix----------------
char	**ft_get_map(int fd); // main function
size_t	ft_strlen(char *s);
int		num_Sub_Str(char const *s, char c);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
//---------------find map size-------------------
int		*ft_map_size(char **map); // return matrix position[y.length][x.length]
int		ft_check_map_error(char **map, int *size);// validate all map error
//--------------run map veriication--------------
int	render_map(t_game *game);
void	store_to_struct(t_game *game);
//-------------events-------------------------
int move_player(int key_sym, void *param);
int	close_game(int Key_sym, void *param);
int	end_of_game(t_game *game, int x, int y);
int is_map_playable(char **map);
#endif
