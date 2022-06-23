/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:35:42 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/23 12:14:12 by mmohamma         ###   ########.fr       */
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
	if (fd == -1)
		return (0);
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

static int	is_pce(char c, t_map *map)
{
	if (c == 'P')
		map->p++;
	if (c == 'C')
		map->c++;
	if (c == 'E')
		map->e++;
	if (c == '1' || c == '0' || c == 'P' || c == 'C'
		|| c == 'E' || c == 'N')
		return (0);
	return (1);
}

static int	is_map_closed_pce(t_map *map)
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
			if (is_pce(str[j][i], map))
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	if (map->c < 1 || map->p != 1 || map->e < 1)
		return (0);
	return (1);
}

int	is_map_valid(char *file, t_map *map)
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
	if (!is_map_closed_pce(map))
	{
		free_map(map);
		return (0);
	}
	return (1);
}
