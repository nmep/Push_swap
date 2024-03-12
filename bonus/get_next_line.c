/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarfi <lgarfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:12:25 by garfi             #+#    #+#             */
/*   Updated: 2023/12/15 20:42:37 by lgarfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(int fd)
{
	static char	*line_static = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line_static = get_line_after_n(fd, line_static);
	if (line_static == NULL)
		return (NULL);
	line = get_line_res(&line_static);
	if (!line)
	{
		free(line_static);
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_line_after_n(int fd, char *line_static)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = NULL;
	while ((readed > 0) && (!ft_strchr(line_static, '\n')))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		readed = read(fd, buffer, BUFFER_SIZE);
		if ((readed == 0 && line_static == NULL) || readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		line_static = ft_strjoin(line_static, buffer);
		if (!line_static || line_static == NULL)
		{
			free(buffer);
			free(line_static);
			return (NULL);
		}
		free(buffer);
	}
	return (line_static);
}

char	*get_line_res(char **line_static)
{
	char	*cpy;
	char	*res;
	int		len;
	int		i;

	len = 0;
	cpy = NULL;
	res = NULL;
	cpy = *line_static;
	while (cpy[len] && cpy[len] != '\n')
		len++;
	if (cpy[len] == '\n')
		len++;
	i = 0;
	res = ft_strdup(cpy, len);
	while ((*line_static)[i] != '\0')
		i++;
	*line_static = ft_strdup((*line_static) + (len), i);
	free(cpy);
	if (!line_static)
		return (NULL);
	return (res);
}

// int main()
// {
// 	// int	fd = open("test", O_RDONLY);
// 	char	*a;

// 	while (1)
// 	{
// 		a = get_next_line(-1);
// 		if (!a)
// 			break;
// 		printf("|%s|", a);
// 		free (a);
// 	}
// 	return (0);
// }