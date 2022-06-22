/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:54:19 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/22 10:58:14 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_load_image(void *mlx, char *path)
{
	int	temp;

	return (mlx_xpm_file_to_image(mlx, path, &temp, &temp));
}

void	load_image(t_data *data)
{
	data->player1 = ft_load_image(data->mlx, "./assets/player1.xpm");
	data->player2 = ft_load_image(data->mlx, "./assets/player2.xpm");
	data->player = data->player1;
	data->player1_2 = ft_load_image(data->mlx, "./assets/player1_2.xpm");
	data->player2_2 = ft_load_image(data->mlx, "./assets/player2_2.xpm");

	data->collect = ft_load_image(data->mlx, "./assets/collect.xpm");
	data->exit = ft_load_image(data->mlx, "./assets/exit.xpm");
	data->wall = ft_load_image(data->mlx, "./assets/wall.xpm");
	data->space = ft_load_image(data->mlx, "./assets/grass.xpm");
	data->enemy = ft_load_image(data->mlx, "./assets/enemy1.xpm");
}
