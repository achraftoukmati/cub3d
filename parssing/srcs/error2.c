/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:02:27 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/21 18:41:16 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	split_map(char *map)
{
	char	*start;
	int		i;

	start = NULL;
	i = 0;
	if (map)
		start = ft_strnstr(map, "1", ft_strlen(map));
	while (start && start[i])
	{
		if (start[i] == '\n' && start[i + 1] == '\n')
		{
			while (start[i])
			{
				if (start[i] != '\n')
				{
					free(map);
					ft_rr("SPLITED_MAP ❌\n");
				}
				i++;
			}
		}
		i++;
	}
}

void	ft_rr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}
