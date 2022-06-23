/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:22:00 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/23 12:13:39 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_game(t_data *data)
{
	quit_game(data);
	return (0);
}

static void	struct_init(t_data *data)
{
	data->steps = 0;
	data->map.c = 0;
	data->map.p = 0;
	data->map.e = 0;
	data->p1.x = 0;
	data->p1.y = 0;
	data->p1.side = RIGHT;
	data->nm.x = 0;
	data->nm.y = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	struct_init(&data);
	if (argc == 2 && is_map_valid(argv[1], &data.map))
	{
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, (data.map.col - 1) * PX,
				(data.map.row + 2) * PX, "so_long");
		load_image(&data);
		mlx_hook(data.mlx_win, 17, 0, exit_game, &data);
		mlx_key_hook(data.mlx_win, ft_key_hook, &data);
		mlx_loop_hook(data.mlx, ft_update, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_putendl_fd("Error", 1);
		return (1);
	}
	return (0);
}
