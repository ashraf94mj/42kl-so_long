/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:27:13 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/22 15:46:44 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//remembber to remove
#include <stdio.h>

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define ESC 65307
# define PX	32

typedef struct s_enemy
{
	int	x;
	int	y;
}				t_enemy;

typedef struct s_player
{
	int	x;
	int	y;
	int	side;
}				t_player;

typedef struct s_map
{
	int		c;
	int		p;
	int		e;
	int		col;
	int		row;
	char	**pos;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			steps;
	void		*player;
	void		*player1;
	void		*player2;
	void		*player1_2;
	void		*player2_2;
	void		*collect;
	void		*exit;
	void		*wall;
	void		*space;
	void		*enemy;
	t_map		map;
	t_player	p1;
	t_enemy		nm;
}				t_data;

/*		so_long.c	*/


/*		map_init.c	*/
int		is_map_valid(char *file, t_map *map);
void	free_map(t_map *map);

/*		load.c		*/
void	load_image(t_data *data);

void	init_enemy(t_data *data);

void	print_map(t_data *data);

int		ft_key_hook(int keycode, t_data *data);

int		ft_update(t_data *data);

void	display_status(t_data *data);
void	quit_game(t_data *data);


#endif
