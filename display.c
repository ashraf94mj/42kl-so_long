/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:43:21 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/23 12:18:15 by mmohamma         ###   ########.fr       */
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

static void	ft_put_player(t_data *data, int x, int y)
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
	while (++y < data->map.row)
	{
		while (++x < data->map.col)
		{
			printf("%c", data->map.pos[y][x]);
			if (data->map.pos[y][x] == '1')
				ft_put_image(data, data->wall, x, y);
			if (data->map.pos[y][x] == '0')
				ft_put_image(data, data->space, x, y);
			if (data->map.pos[y][x] == 'E')
				ft_put_image(data, data->exit, x, y);
			if (data->map.pos[y][x] == 'P')
				ft_put_player(data, x, y);
			if (data->map.pos[y][x] == 'C')
				ft_put_image(data, data->collect, x, y);
			if (is_enemy(&data->map.pos[y][x]))
				ft_put_image(data, data->enemy, x, y);
		}
		x = -1;
	}
	printf("\n");
}
