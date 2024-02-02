/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:17:40 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/02 04:11:31 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int has_wall_at(t_data *data, float x, float y)
{
  int  x_m;
  int  y_m;

 if (x < 0 || y < 0)
  return (0);
 x_m = floor (x / data->map->unit); 
 y_m = floor (y / data->map->unit);
 if ((y_m >= data->map->map_height || x_m >= data->map->map_width))
  return (0);
 if (data->map->map[y_m] && x_m <= (int)strlen(data->map->map[y_m]))
  if (data->map->map[y_m][x_m] == '1' )
   return (0);
 return (1);
}

float normalize_angle(float angle) 
{
    while (angle < 0) angle += 2 * M_PI;
    while (angle >= 2 * M_PI) angle -= 2 * M_PI;
    return angle;
}
int    get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a | 0xFF);
}

int    get_color_at_position(mlx_texture_t *texture, int x, int y)
{
    int    offset;
    int    red;
    int    green;
    int    blue;
    int    alpha;

    offset = (y * texture->width + x) * texture->bytes_per_pixel;
    red = texture->pixels[offset++];
    green = texture->pixels[offset++];
    blue = texture->pixels[offset++];
    alpha = texture->pixels[offset++];
    return (get_rgba(red, green, blue, alpha));
}
