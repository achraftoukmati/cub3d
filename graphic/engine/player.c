/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:23:57 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 17:39:43 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	locat_player(char **map, char target)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'S' || map[y][x] == 'N' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				if (target == 'X')
					return (((x + 1) * 80) - 40);
				else
					return (((y + 1) * 80) - 40);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	update_player(t_data *data)
{
	key_press(data);
	data->player->rotation_angel += data->player->turn_diraction
		* data->player->rotation_speed;
	data->player->move_step = data->player->walk_diraction
		* data->player->move_speed;
	data->player->strafe_step = data->player->walk_lr_diraction
		* data->player->move_speed;
	data->player->n_x = data->player->player_x + (data->player->move_step
			* cos(data->player->rotation_angel)) + (data->player->strafe_step
			* cos(data->player->rotation_angel + M_PI / 2));
	data->player->n_y = data->player->player_y + (data->player->move_step
			* sin(data->player->rotation_angel)) + (data->player->strafe_step
			* sin(data->player->rotation_angel + M_PI / 2));
	if (has_wall_at(data, data->player->n_x, data->player->n_y))
	{
		data->player->player_x = data->player->n_x;
		data->player->player_y = data->player->n_y;
	}
}
