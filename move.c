/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:44:27 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/20 11:25:50 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	display_status(t_data *data)
{
	char	*str;
	char	*str2;

	str = ft_itoa(data->steps);
	str2 = ft_itoa(data->map.c);
	mlx_string_put(data->mlx, data->mlx_win, PX, (data->map.row + 0.5) * PX,
		0x0000FFFF, "Steps:");
	mlx_string_put(data->mlx, data->mlx_win, 3 * PX, (data->map.row + 0.5) * PX,
		0x0000FFFF, str);
	mlx_string_put(data->mlx, data->mlx_win, PX, (data->map.row + 1.5) * PX,
		0x0000FFFF, "Collect:");
	mlx_string_put(data->mlx, data->mlx_win, 3 * PX, (data->map.row + 1.5) * PX,
		0x0000FFFF, str2);
	free(str);
	free(str2);
}


void	ft_put_image(t_data *data, void *c, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, c, x * PX, y * PX);
}


void	ft_put_player(t_data *data, int x, int y)
{
	ft_put_image(data, data->player, x, y);
	data->p1.x = x;
	data->p1.y = y;
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	// printf("%d-%d\n", data->map.row, data->map.col);   // for checking ya
	while (++y < data->map.row)
	{
		while (++x < data->map.col)
		{
			// printf("%c", data->map.pos[y][x]);   // for checking ya
			if (data->map.pos[y][x] == '1')
				ft_put_image(data, data->wall, x, y);
			if (data->map.pos[y][x] == '0')
				ft_put_image(data, data->space, x, y);
			if (data->map.pos[y][x] == 'E')
				ft_put_image(data, data->exit, x, y);
			if (data->map.pos[y][x] == 'P')
			{
				ft_put_image(data, data->space, x, y);	
				ft_put_player(data, x, y);
			}
			if (data->map.pos[y][x] == 'C')
				ft_put_image(data, data->collect, x, y);
			if (data->map.pos[y][x] == 'N')
				ft_put_image(data, data->enemy, x, y);
		}
		x = -1;
	}
}



void	quit_game(t_data *data)
{
	ft_putendl_fd("ESC - Game will quit", 1);
	mlx_destroy_image(data->mlx, data->player1);
	mlx_destroy_image(data->mlx, data->player2);
	mlx_destroy_image(data->mlx, data->collect);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->space);


	free_map(&data->map);

	mlx_destroy_window(data->mlx, data->mlx_win);

	mlx_loop_end(data->mlx);

	// exit(0);
}

void	check(t_data *data, int x, int y)
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
	else if (data->map.pos[data->p1.y + y][data->p1.x + x] == 'E' && data->map.c == 0)
		quit_game(data);
}

int	key_hook(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	if (keycode == UP)
		check(data, 0, -1);
	else if (keycode == LEFT)
	{
		check(data, -1, 0);
		data->p1.side = LEFT;
	}
	else if (keycode == DOWN)
		check(data, 0, 1);
	else if (keycode == RIGHT)
	{
		check(data, 1, 0);
		data->p1.side = RIGHT;
	}
	print_map(data);
	display_status(data);
	if (keycode == ESC)
		quit_game(data);
	return (0);
}


// int	ft_update(t_data *data)
// {
// 	static int	frame;

// 	// mlx_clear_window(data->mlx, data->mlx_win);

// 	frame++;
// 	if (frame == ANIMATION)
// 	{
// 		if (data->p1.side == RIGHT)
// 			data->player = data->player2;
// 		else
// 			data->player = data->player2_2;
// 	}
// 	else if (frame >= ANIMATION * 2)
// 	{
// 		frame = 0;
// 		if (data->p1.side == RIGHT)
// 			data->player = data->player1;
// 		else
// 			data->player = data->player1_2;
// 	}
// 	print_map(data);
// }
