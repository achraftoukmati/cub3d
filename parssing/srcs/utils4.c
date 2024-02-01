/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:04:41 by alotfi            #+#    #+#             */
/*   Updated: 2024/01/17 18:05:28 by alotfi           ###   ########.fr       */
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

int	f_check(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if ((str[i] == '1' && str[i + 1] == 32 && str[i + 2] == 'N'))
			return (1);
		if ((str[i] == 'N' && str[i + 1] == 32 && str[i + 2] == '1'))
			return (1);
		if ((str[i] == '0' && str[i + 1] == 32 && str[i + 2] == 'E'))
			return (1);
		if ((str[i] == 'E' && str[i + 1] == 32 && str[i + 2] == '0'))
			return (1);
		if ((str[i] == '1' && str[i + 1] == 32 && str[i + 2] == 'E'))
			return (1);
		if ((str[i] == 'E' && str[i + 1] == 32 && str[i + 2] == '1'))
			return (1);
		if ((str[i] == '0' && str[i + 1] == 32 && str[i + 2] == 'W'))
			return (1);
		if ((str[i] == 'W' && str[i + 1] == 32 && str[i + 2] == '0'))
			return (1);
		i++;
	}
	return (0);
}

int	f_check2(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if ((str[i] == '0' && str[i + 1] == 32 && str[i + 2] == 'N'))
			return (1);
		if ((str[i] == 'N' && str[i + 1] == 32 && str[i + 2] == '0'))
			return (1);
		if ((str[i] == '1' && str[i + 1] == 32 && str[i + 2] == 'W'))
			return (1);
		if ((str[i] == 'W' && str[i + 1] == 32 && str[i + 2] == '1'))
			return (1);
		i++;
	}
	return (0);
}

int	f_check1(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '0' && str[i + 1] == 32 && str[i + 2] == '0')
			return (1);
		if ((str[i] == '0' && str[i + 1] == 32 && str[i + 2] == '1'))
			return (1);
		if ((str[i] == '1' && str[i + 1] == 32 && str[i + 2] == '0'))
			return (1);
		if ((str[i] == '0' && str[i + 1] == 32 && str[i + 2] == 'S'))
			return (1);
		if ((str[i] == 'S' && str[i + 1] == 32 && str[i + 2] == '0'))
			return (1);
		if ((str[i] == '1' && str[i + 1] == 32 && str[i + 2] == 'S'))
			return (1);
		if ((str[i] == 'S' && str[i + 1] == 32 && str[i + 2] == '1'))
			return (1);
		i++;
	}
	return (0);
}
