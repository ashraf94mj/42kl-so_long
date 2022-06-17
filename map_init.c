/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:35:42 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/17 14:57:54 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	is_ber_file(char *file) 
{
	const char	*str = ft_strrchr(file, '.');

	if (!str)
		return (0);
	if (ft_strncmp(str, ".ber\0", 5) == 0)
		return (1);
	return (0);
}

static int	is_map_rectangle(t_map *map, char *file)
{
	const int	fd = open(file, O_RDONLY);
	int			count;
	char		*line;

	count = 0;
	line = get_next_line(fd);
	map->col = ft_strlen(line);
	while (line)
	{
		if ((int)ft_strlen(line) != map->col)
		{
			free(line);
			return (0);
		}
		count++;
		free(line);
		line = get_next_line(fd);
	}
	map->row = count;
	close(fd);
	return (1);
}

static void	is_pce(char c, t_data *data)
{
	if (c == 'P')
		data->p++;
	if (c == 'C')
		data->c++;
	if (c == 'E')
		data->e++;
}

static int	is_map_closed_pce(t_map *map, t_data *data)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 1;
	str = map->pos;

	while (i < map->col - 1)
	{
		if (str[0][i] != '1' || str[map->row - 1][i] != '1')
			return (0);
		while (j < map->row - 1)
		{
			if (str[j][0] != '1' || str[j][map->col - 2] != '1')
				return (0);
			is_pce(str[j][i], data);
			j++;
		}
		j = 1;
		i++;
	}
	if (data->c < 1 || data->p != 1 || data->e < 1)
		return (0);
	return (1);
}

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

int	is_map_valid(t_map *map, char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (!is_map_rectangle(map, file) || !is_ber_file(file))
		return (0);
	map->pos = malloc(sizeof(char *) * map->row);
	if (!map->pos)
		return (0);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map->pos[i++] = line;
		line = get_next_line(fd);
	}
	close(fd);
	if (!is_map_closed_pce(map, data))
	{
		free_map(map);
		return (0);
	}
	return (1);
}
