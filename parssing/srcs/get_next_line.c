/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:00:55 by alotfi            #+#    #+#             */
/*   Updated: 2024/01/17 13:03:45 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include "../headers/cub3d.h"

int	ft_checknl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*get_firstline(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_afterline(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	res = malloc(ft_strlen(str) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*read_fd(int fd, char *str)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (i != 0 && !(ft_checknl(str)))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_str_join(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_fd(fd, str);
	if (!str)
		return (NULL);
	line = get_firstline(str);
	str = get_afterline(str);
	return (line);
}
