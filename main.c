/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:12:05 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 18:39:36 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./graphic/cub3d.h"

int	main(int ac, char **av)
{
	t_game	glo;
	t_data	data;

	if (ac != 2)
		ft_rr("UNVALID_INPUT 😨\n");
	glo.map_name = av[1];
	cub_all(&glo);
	chkeck_player(&glo);
	init(&data, &glo);
	start_game(&data);
	exiting(&data, 0);
	return (0);
}
