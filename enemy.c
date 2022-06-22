/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:28:24 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/22 17:53:31 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_enemy(char *c)
{
	static int	i;
	const char	*s = "LKJI";

	*c = ft_toupper(*c);
	if (*c == 'N')
	{
		*c = s[i++];
		if (i > 3)
			i = 0;
	}
	if (*c == 'I' || *c == 'J' || *c == 'K' || *c == 'L')
		return (1);
	return (0);
}

static void	check_enemy(t_data *data, int y, int x)
{
	if (data->map.pos[data->nm.y + y][data->nm.x + x] == 'P')
		quit_game(data);
	else if (data->map.pos[data->nm.y + y][data->nm.x + x] == '0')
	{
		data->map.pos[data->nm.y + y][data->nm.x + x]
			= ft_tolower(data->map.pos[data->nm.y][data->nm.x]);
		data->map.pos[data->nm.y][data->nm.x] = '0';
	}
	else
		data->map.pos[data->nm.y][data->nm.x] = 'N';
}

void	enemy_move(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (++y < data->map.row)
	{
		while (++x < data->map.col)
		{
			data->nm.y = y;
			data->nm.x = x;
			if (data->map.pos[y][x] == 'I')
				check_enemy(data, -1, 0);
			else if (data->map.pos[y][x] == 'J')
				check_enemy(data, 0, -1);
			else if (data->map.pos[y][x] == 'K')
				check_enemy(data, 1, 0);
			else if (data->map.pos[y][x] == 'L')
				check_enemy(data, 0, 1);
		}
		x = -1;
	}
}
