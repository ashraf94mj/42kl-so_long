/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:22:00 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/17 21:41:27 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	quit_game(t_data *data)
// {
	
// }



static int	exit_game(void)
{
	exit(0);
	return (1);
}

static void	struct_init(t_data *data)
{
	data->steps = 0;
	data->c = 0;
	data->p = 0;
	data->e = 0;
}

static void	display_status(t_data *data, t_map *map)
{
	char	*str;

	str = ft_itoa(data->steps);
	mlx_string_put(data->mlx, data->mlx_win, 0.5 * PX, (map->row + 0.5) * PX,
		0x0000FFFF, "Moves: ");
	mlx_string_put(data->mlx, data->mlx_win, 0.7 * PX, (map->row + 0.5) * PX,
		0x0000FFFF, str);
	
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	struct_init(&data);
	if (argc == 2 && is_map_valid(&map, argv[1], &data))
	{
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, (map.col - 1) * PX, (map.row + 1) * PX, "so_long");
		load_image(&data);
		print_map(&map, &data);

		mlx_hook(data.mlx_win, 17, 0, exit_game, &data);

		mlx_key_hook(data.mlx_win, key_hook, &data);
		// mlx_loop_hook(data.mlx, ft_update, &data);


		display_status(&data, &map);
		mlx_loop(data.mlx);
	}
	else
		ft_putendl_fd("Error", 1);
	return (0);
}
