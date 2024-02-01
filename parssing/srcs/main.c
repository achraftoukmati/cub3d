/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:26:54 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/01 22:01:48 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	ft_check_map3(t_game *glo)
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
			if (ft_strchr("0", glo->map_ptr[i][j]))
			{
				w = j;
				if (glo->map_ptr[i - 1][w] == '\0'
					&& ft_fchecker(&glo->map_ptr[i][w], '1', '1'))
					ft_rr("UNVALID_MAP : ^_^\n");
			}
			j++;
		}
		i++;
	}
}

void	chkeck_player(t_game *glo)
{
	int	i;
	int	j;

	i = 0;
	while (glo->map_ptr[i])
	{
		j = 0;
		while (glo->map_ptr[i][j])
		{
			if (glo->map_ptr[i][j] == ' ' && glo->map_ptr[i][j + 1] == 'S'
				&& glo->map_ptr[i][j] == ' ')
				ft_rr("PLAYER_IN_THE_VOID ❌\n");
			if (glo->map_ptr[i][j] == ' ' && glo->map_ptr[i][j + 1] == 'W'
				&& glo->map_ptr[i][j] == ' ')
				ft_rr("PLAYER_IN_THE_VOID ❌\n");
			if (glo->map_ptr[i][j] == ' ' && glo->map_ptr[i][j + 1] == 'N'
				&& glo->map_ptr[i][j] == ' ')
				ft_rr("PLAYER_IN_THE_VOID ❌\n");
			if (glo->map_ptr[i][j] == ' ' && glo->map_ptr[i][j + 1] == 'E'
				&& glo->map_ptr[i][j] == ' ')
				ft_rr("PLAYER_IN_THE_VOID ❌\n");
			j++;
		}
		i++;
	}
}

int	ft_main(int ac, char **av)
{
	t_game	glo;
	int		i;

	if (ac != 2)
	{
		ft_rr("UNVALID_INPUT 😨\n");
	}
	glo.map_name = av[1];
	cub_all(&glo);
	chkeck_player(&glo);
	i = 0;
	while (glo.map_ptr[i])
	{
		printf("%s\n", glo.map_ptr[i]);
		i++;
	}
	return (0);
}
