/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:54:19 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/22 16:41:36 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int		i;
	char	**matrix;

	matrix = map->pos;
	i = 0;
	while (i < map->row)
		free(matrix[i++]);
	free(matrix);
}

void	*ft_load_image(void *mlx, char *path)
{
	int	temp;

	return (mlx_xpm_file_to_image(mlx, path, &temp, &temp));
}

void	load_image(t_data *data)
{
	data->player1 = ft_load_image(data->mlx, "./assets/player1.xpm");
	data->player2 = ft_load_image(data->mlx, "./assets/player2.xpm");
	data->player1_2 = ft_load_image(data->mlx, "./assets/player1_2.xpm");
	data->player2_2 = ft_load_image(data->mlx, "./assets/player2_2.xpm");
	data->player = data->player1;
	data->collect = ft_load_image(data->mlx, "./assets/collect.xpm");
	data->exit = ft_load_image(data->mlx, "./assets/exit.xpm");
	data->wall = ft_load_image(data->mlx, "./assets/wall.xpm");
	data->space = ft_load_image(data->mlx, "./assets/grass.xpm");
	data->enemy = ft_load_image(data->mlx, "./assets/enemy1.xpm");
}

void	ft_put_image(t_data *data, void *c, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, c, x * PX, y * PX);
}

void	quit_game(t_data *data)
{
	ft_putendl_fd("Game will quit", 1);
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
