/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:44:27 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/17 21:21:19 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_data *data, void *c, int j, int i)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, c, j * PX, i * PX);
}

void	print_map(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < map->row)
	{
		while (++j < map->col)
		{
			// printf("%c", map->pos[i][j]);
			if (map->pos[i][j] == '1')
				ft_put_image(data, data->wall, j, i);
			// if (map->pos[i][j] == '0')
			// 	ft_put_image(data, data->space, j, i);
			if (map->pos[i][j] == 'E')
				ft_put_image(data, data->exit, j, i);
			// if (map->pos[i][j] == 'P')
			// 	ft_put_image(data, data->player, j, i);
			// if (map->pos[i][j] == 'C')
			// 	ft_put_image(data, data->collect, j, i);
			// if (map->pos[i][j] == 'N')
			// 	ft_put_image(data, data->enemy, j, i);
		}
		j = -1;
	}
}

int	key_hook(int keycode, t_data *data, t_map *map)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	if (keycode == ESC)
	{
		ft_putendl_fd("ESC - Game will quit", 1);
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_loop_end(data->mlx);
	}
	else if (keycode == UP)
		ft_put_image(data, data->collect, 3, 0);
		// printf("UP!\n");
	else if (keycode == LEFT)
		ft_put_image(data, data->collect, 2, 1);
		// printf("Left!\n");
	else if (keycode == DOWN)
		printf("Down!\n");
	else if (keycode == RIGHT)
		printf("Right!\n");
	else
		printf("Hello from key_hook!%d\n", keycode); //

	print_map(map, data);
	ft_put_image(data, data->collect, 3, 1);
	return (0);
}

int	ft_update(t_data *data, t_map *map)
{
	static int	frame;

	frame++;
	if (frame == ANIMATION)
	{
		// printf("%d\n", frame);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, 2.1 * PX, 1.1 * PX);
	}
	else if (frame >= ANIMATION * 2)
	{
		frame = 0;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, 2 * PX, 1 * PX);

	}

}
