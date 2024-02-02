/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:23:57 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/02 02:50:07 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int locat_player(char **map, char target)
{
    int y;
    int x;
    y = 0;
    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if(map[y][x] == 'N')
            {
                if(target == 'x')
                    return (((x + 1 ) * 40 ) + 80);
                else
                    return (((y + 1) * 40) + 80);
            }
            x++;
        }
        y++;
    }
    
    return 0;
}

void update_player(t_data *data)
{
    key_press(data);
    data->player->rotation_angel += data->player->turn_diraction * data->player->rotation_speed;
    int move_step = data->player->walk_diraction * data->player->move_speed;
    int strafe_step = data->player->walk_lr_diraction * data->player->move_speed;
    float n_x = data->player->player_x + (move_step * cos(data->player->rotation_angel)) + (strafe_step * cos(data->player->rotation_angel + M_PI/2)); 
    float n_y = data->player->player_y + (move_step * sin(data->player->rotation_angel)) + (strafe_step * sin(data->player->rotation_angel + M_PI/2));
    if (has_wall_at(data, n_x, n_y)) 
    {
        data->player->player_x = n_x;
        data->player->player_y = n_y;
    }
    // mlx_circle(data->mlx->img,data->player->player_x,data->player->player_y,data->player->radius);
    // mlx_line(data->mlx->img, data->player->player_x, data->player->player_y, data->player->player_x + cos(data->player->rotation_angel) * 50, data->player->player_y + sin(data->player->rotation_angel) * 50, RED);
}
