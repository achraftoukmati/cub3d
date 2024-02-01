/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:20:20 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/01 07:35:32 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int get_color(char cell)
{
    if (cell == '1')
        return BLUE;
    else if (cell == '0')
        return WHITE;
    else if (cell == 'P')
        return WHITE;
    else
        return -1; 
}

void fill_map(t_data *data)
{
    int i = 0;
    int j = 0;
    while(i < S_W)
    {
        j = 0;
        while(j < S_H )
        {
            if(j <( S_H / 2))
                mlx_put_pixel(data->mlx->img,i,j,BLACK);
            else
                mlx_put_pixel(data->mlx->img,i,j,GRAY);
            j++;
        }
        i++;
    }

}
void update_map(t_data *data)
{
    int idx = 0;
   
     mlx_delete_image(data->mlx->mlx, data->mlx->img); // delete the image
    data->mlx->img = mlx_new_image(data->mlx->mlx, S_W, S_H);
    fill_map(data);

    // while (data->map->map[idx])
    // {
    //     int y = 0;
    //     while (data->map->map[idx][y])
    //     {
    //         int color = get_color(data->map->map[idx][y]);
    //         int x_start = y * data->map->unit;
    //         int y_start = idx * data->map->unit;
    //         int x_end = x_start + data->map->unit;
    //         int y_end = y_start + data->map->unit;
    //         int i = x_start;
    //         while (i < x_end )
    //         {
    //             int j = y_start;
    //             while (j < y_end )
    //             {
                    // mlx_put_pixel(data->mlx->img, i, j, color);
    //                 j++;
    //             }
    //             i++;
    //         }
    //         y++;
    //     }
    //     idx++;
    // }
    
}
