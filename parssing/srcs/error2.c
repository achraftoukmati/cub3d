/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:02:27 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/02 17:00:56 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	split_map(char *map)
{
	char	*start = NULL;
	int		i;

	i = 0;
	
	if(map)
		start = ft_strnstr(map, "111", ft_strlen(map));
	while (start &&  start[i])
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
