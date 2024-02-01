/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:12:05 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/01 06:24:23 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./graphic/cub3d.h"


int init_player(t_data *data)
{
    data->player->radius = 3;
    data->player->player_x = locat_player(data->map->map,'x');
    data->player->player_y = locat_player(data->map->map,'y');
    data->player->move_speed = 8;
    data->player->rotation_angel = M_PI / 2;
    data->player->walk_diraction = 0;
    data->player->turn_diraction = 0;
    data->player->rotation_speed = 5 * (M_PI / 180);
    data->player->FOV_angle = 60 * (M_PI / 180);
    data->player->wall_strip_width = 1;
    data->player->num_rays = S_W;
    data->player->rays = malloc(sizeof(t_rays) * (data->player->num_rays + 1));
    return (0);
}

int init_map(t_map *data)
{    

    data->map = malloc(sizeof(char *) * 6);
    data->map[0] = strdup("11111111111111111111111");
    data->map[1] = strdup("10000000100000000000001");
    data->map[2] = strdup("100000010000000P0000001");
    data->map[3] = strdup("100000000000000000000011");
    data->map[4] = strdup("1111111111111111111111111");
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

void leaks_()
{
   system("leaks cub"); 
}

void free_all(t_data *data)
{
    int i = 0;
    while(data->map->map[i])
    {
        free(data->map->map[i]);
        i++;
    }
    free(data->map->map);
    if(data->map)
        free(data->map);
    if(data->player->rays)
        free(data->player->rays);
    if(data->player)
        free(data->player);
    if(data->mlx)
        free(data->mlx);
    if(data->vars)
        free(data->vars);
}

void exiting(t_data *data,int var)
{
    mlx_delete_image(data->mlx->mlx, data->mlx->img);
    mlx_close_window(data->mlx->mlx);
    mlx_terminate(data->mlx->mlx);
    mlx_delete_texture(data->mlx->wall);
    free_all(data);
    leaks_();
    if(var != ERROR)
        printf("Game closed!\n");
    exit(var);
}

int main(void)
{
    t_data data;
    init(&data);
    start_game(&data);
    exiting(&data,0);
    return 0;
}
