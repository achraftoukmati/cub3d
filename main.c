/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:12:05 by atoukmat          #+#    #+#             */
/*   Updated: 2024/01/30 14:30:58 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./graphic/cub3d.h"


int init_player(t_data *data)
{
    data->player->radius = 3;
    data->player->player_x = locat_player(data->map->map,'x');
    data->player->player_y = locat_player(data->map->map,'y');
    data->player->move_speed = 10;
    data->player->rotation_angel = M_PI / 2;
    data->player->walk_diraction = 0;
    data->player->turn_diraction = 0;
    data->player->rotation_speed = 6 * (M_PI / 180);
    data->player->FOV_angle = 60 * (M_PI / 180);
    data->player->wall_strip_width = 1;
    data->player->num_rays = S_W;
    data->player->rays = malloc(sizeof(t_rays) * (data->player->num_rays + 1));
    return (0);
}

int init_map(t_map *data)
{    

    data->map = malloc(sizeof(char *) * 6);
    data->map[0] = strdup("1111111111111111");
    data->map[1] = strdup("100000001000001");
    data->map[2] = strdup("10000001P00001");
    data->map[3] = strdup("1000000000000011");
    data->map[4] = strdup("1111111111111111");
    data->map[5] = NULL;
    data->map_height = 5;
    data->map_width = 16;
    data->unit = 80;
    data->angle = 0.0f;
    return (0);
}

int init(t_data *data)
{
    data->map = malloc(sizeof(t_map));
    init_map(data->map);
    data->player = malloc(sizeof(t_player));
    init_player(data);
    data->mlx = malloc(sizeof(t_mlx));
    data->vars = malloc(sizeof(t_rays));
    return 0;
}

int main(int ac , char **av)
{
    t_data *data = malloc(sizeof(t_data));
    init(data);
    start_game(data);
    return 0;

}