/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:04:41 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/18 19:39:20 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	ft_checker(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != '\0')
		i++;
	if (str[i - 2] == c)
		return (1);
	return (0);
}

int	check_map_name(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u' && str[i
			+ 3] == 'b')
			return (1);
		else
			i++;
	}
	return (0);
}

int ger(char *str)
{
	int i = 0;

	while(str && str[i])
	{
		if(str[i] == '1')
			i++;
		else 
		return 1;
	}
	return 0;
}
int ger1(char *str)
{
	int i = 0;

	while(str && str[i])
	{
		if(str[i] == '1' || str[i] == 32)
			i++;
		else 
		return 1;
	}
	return 0;
}

void kechma(t_game *glo)
{
	int i = 1;
	int j = 0;
	int w = 0;

	while(glo->map_ptr[i])
	{
		j = 0;
		while(glo->map_ptr[i][j])
		{
			if(ft_strchr("1", glo->map_ptr[i][j]))
			{
				w = j;
				
				if(glo->map_ptr[i - 1][w] =='\0' && ger(&glo->map_ptr[i][j]) == 1)
					ft_rr("NIKE \n");
				
			}
			j++;
		}
		i++;
	}
}