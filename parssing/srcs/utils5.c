/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:02:28 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/02 17:04:01 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_check_map(t_game *glo)
{
	int	i;
	int	w;
	int	flag;
	int	j;

	i = 1;
	w = 0;
	flag = 0;
	while (glo->map_ptr[i])
	{
		j = 0;
		while (glo->map_ptr[i][j])
		{
			if (ft_strchr("NSWE", glo->map_ptr[i][j]))
				flag = 1;
			j++;
		}
		i++;
	}
	if (flag == 0)
		ft_rr("I_THINK_YOU_FORGOT_THE_PLAYER ❌\n");
}

void	ft_check_map2(t_game *glo)
{
	int	i;
	int	w;
	int	j;

	i = 1;
	w = 0;
	while (glo->map_ptr[i])
	{
		j = 0;
		while (glo->map_ptr[i][j])
		{
			if (ft_strchr("1", glo->map_ptr[i][j]))
			{
				w = j;
				if (glo->map_ptr[i - 1][w] && glo->map_ptr[i - 1][w] == '\0'
					&& ft_fchecker(&glo->map_ptr[i][w], '1', '1'))
					ft_rr("UNVALID_MAP : ^_^\n");
			}
			j++;
		}
		i++;
	}
	ft_check_map3(glo);
}

void	check_under_zero(t_game *glo)
{
	int	i;
	int	w;
	int	j;

	i = 0;
	while (glo->map_ptr[i] != '\0')
	{
		j = 0;
		w = 0;
		while (glo->map_ptr[i][j])
		{
			if (ft_strchr("0", glo->map_ptr[i][j]))
			{
				w = j;
				if (glo->map_ptr[i + 1][w] == 32 || glo->map_ptr[i
					- 1][w] == 32)
					ft_rr("NOT_A_VALID_PATH ❌\n");
			}
			j++;
		}
		i++;
	}
}

void	cub_all(t_game *glo)
{
	read_map(glo);
	get_ptrs(glo);
	get_ptrs2(glo);
	check_map(glo);
	syntax_check(glo);
	ft_check_map(glo);
	valid_path(glo);
	ft_check_map2(glo);
	check_under_zero(glo);
}
