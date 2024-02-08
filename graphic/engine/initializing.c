/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:35:13 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 18:35:55 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_map(t_map *data, t_game *ayoub)
{
	data->map = ayoub->map_ptr;
	data->map_height = max_h(data->map);
	data->map_width = max_w(data->map);
	data->unit = 80;
	data->ea = ayoub->EA_s[1];
	data->no = ayoub->NO_s[1];
	data->so = ayoub->SO_s[1];
	data->we = ayoub->WE_s[1];
	data->angle = 0.0f;
	return (0);
}

int	init(t_data *data, t_game *ayoub)
{
	data->map = malloc(sizeof(t_map));
	init_map(data->map, ayoub);
	data->player = malloc(sizeof(t_player));
	init_player(data);
	data->mlx = malloc(sizeof(t_mlx));
	data->mlx->celling = get_rgba(ft_atoi(ayoub->F_s[1]),
			ft_atoi(ayoub->F_s[2]), ft_atoi(ayoub->F_s[3]), 0);
	data->mlx->floor = get_rgba(ft_atoi(ayoub->C_s[1]), ft_atoi(ayoub->C_s[2]),
			ft_atoi(ayoub->C_s[3]), 1);
	data->vars = malloc(sizeof(t_rays));
	return (0);
}

int	init_player(t_data *data)
{
	data->player->radius = 3;
	data->player->player_x = locat_player(data->map->map, 'X');
	data->player->player_y = locat_player(data->map->map, 'Y');
	data->player->move_speed = 8;
	data->player->rotation_angel = M_PI / 2;
	data->player->walk_diraction = 0;
	data->player->turn_diraction = 0;
	data->player->rotation_speed = 2 * (M_PI / 180);
	data->player->fov_angle = 60 * (M_PI / 180);
	data->player->wall_strip_width = 1;
	data->player->num_rays = S_W;
	data->player->rays = malloc(sizeof(t_rays) * (data->player->num_rays + 1));
	return (0);
}
