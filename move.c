/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:44:27 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/22 17:53:07 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check(t_data *data, int y, int x)
{
	if (data->map.pos[data->p1.y + y][data->p1.x + x] == '0')
	{
		data->map.pos[data->p1.y][data->p1.x] = '0';
		data->map.pos[data->p1.y + y][data->p1.x + x] = 'P';
		data->steps++;
	}
	else if (data->map.pos[data->p1.y + y][data->p1.x + x] == 'C')
	{
		data->map.pos[data->p1.y][data->p1.x] = '0';
		data->map.pos[data->p1.y + y][data->p1.x + x] = 'P';
		data->steps++;
		data->map.c--;
	}
	else if (is_enemy(&data->map.pos[data->p1.y + y][data->p1.x + x]))
		quit_game(data);
	else if (data->map.pos[data->p1.y + y][data->p1.x + x] == 'E'
		&& data->map.c == 0)
		quit_game(data);
}

int	ft_key_hook(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	if (keycode == UP)
		check(data, -1, 0);
	else if (keycode == LEFT)
	{
		check(data, 0, -1);
		data->p1.side = LEFT;
	}
	else if (keycode == DOWN)
		check(data, 1, 0);
	else if (keycode == RIGHT)
	{
		check(data, 0, 1);
		data->p1.side = RIGHT;
	}
	print_map(data);
	display_status(data);
	if (keycode == ESC)
		quit_game(data);
	return (0);
}

int	ft_update(t_data *data)
{
	static int	frame;

	frame++;
	if (frame == 10 || frame == 30)
	{
		if (data->p1.side == RIGHT)
			data->player = data->player2;
		else
			data->player = data->player2_2;
	}
	else if (frame == 20 || frame == 40)
	{
		if (data->p1.side == RIGHT)
			data->player = data->player1;
		else
			data->player = data->player1_2;
	}
	else if (frame > 50)
	{
		frame = 0;
		enemy_move(data);
	}
	print_map(data);
	display_status(data);
	return (1);
}
