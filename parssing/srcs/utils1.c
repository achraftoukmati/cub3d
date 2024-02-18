/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:58:25 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/17 19:17:54 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	ft_fchecker(char *str, char c, char w)
{
	int	i;

	i = 0;
	while (str && str[i] == 32)
		i++;
	while (str && str[i] != '\0')
	{
		if (str[i] == c || str[i] == w)
			i++;
		else
			return (1);
	}
	return (0);
}

int	weet(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[0] == '1' || str[0] == ' ')
			return (1);
		return (0);
	}
	return (0);
}

int	weet2(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	while (str[i] == '\0')
	{
		if (str[i] == '\0' && str[i - 1] == '1')
			return (1);
		return (0);
	}
	return (0);
}

void	weet3(t_game *glo)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (glo->map_ptr[i])
	{
		j = 0;
		while (glo->map_ptr[i][j])
		{
			if (glo->map_ptr[i][j] == 'N' || glo->map_ptr[i][j] == 'S'
				|| glo->map_ptr[i][j] == 'W' || glo->map_ptr[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		ft_rr("THERE_IS_MORE_THAN_ONE_PLAYER ❌\n");
		
}
