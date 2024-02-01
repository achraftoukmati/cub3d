/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:59:36 by alotfi            #+#    #+#             */
/*   Updated: 2024/01/19 10:15:05 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	table_counter(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	*ftt_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

void	kmala_split(char *str, char c, char w)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == c || str[i] == w))
			i++;
		while (str[i] && (str[i] != c && str[i] != w))
			i++;
	}
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (0);
	}
	return (1);
}
