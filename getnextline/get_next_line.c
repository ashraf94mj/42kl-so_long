/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmohamma <mmohamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:03:37 by mmohamma          #+#    #+#             */
/*   Updated: 2022/06/07 15:20:17 by mmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	i_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	read_file(int fd, char *buf, char **line)
{
	char	*temp;
	int		size_read;

	size_read = read(fd, buf, BUFFER_SIZE);
	if (size_read > 0)
	{
		buf[size_read] = '\0';
		if (!*line)
			*line = ft_substr(buf, 0, size_read);
		else
		{
			temp = *line;
			*line = ft_strjoin(*line, buf);
			free(temp);
		}
	}
	else
		return ;
	if (i_newline(*line) < 0)
		read_file(fd, buf, line);
}

char	*output_line(char **line)
{
	char	*new_line;
	char	*output;
	char	*temp;

	if (*line[0] == '\0')
	{
		free(*line);
		*line = 0;
		return (0);
	}
	if (i_newline(*line) < 0)
	{
		output = ft_substr(*line, 0, ft_strlen(*line));
		free (*line);
		*line = 0;
		return (output);
	}
	output = ft_substr(*line, 0, i_newline(*line) + 1);
	temp = *line;
	new_line = *line + i_newline(*line) + 1;
	*line = ft_substr(new_line, 0, ft_strlen(new_line));
	free (temp);
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE < 1 || !buf)
	{
		free(buf);
		return (0);
	}
	if (!line || i_newline(line) == -1)
		read_file(fd, buf, &line);
	free(buf);
	if (!line)
		return (0);
	return (output_line(&line));
}
