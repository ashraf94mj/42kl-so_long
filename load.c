/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:54:19 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/17 17:20:22 by mmohamma         ###   ########.fr       */
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
	data->player = ft_load_image(data->mlx, "./assets/sprite.xpm");
	data->collect = ft_load_image(data->mlx, "./assets/collection.xpm");
	data->exit = ft_load_image(data->mlx, "./assets/exit.xpm");
	data->wall = ft_load_image(data->mlx, "./assets/wall.xpm");
	data->space = ft_load_image(data->mlx, "./assets/plains.xpm");
	// data->enemy = ft_load_image(data->mlx, "./assets/");
}


