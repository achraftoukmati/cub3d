/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:12:05 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/21 15:50:52 by alotfi           ###   ########.fr       */
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
