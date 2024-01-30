/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:14:30 by atoukmat          #+#    #+#             */
/*   Updated: 2024/01/30 13:40:02 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int unit_circle(float angle, char c) 
{
 if (c == 'x')
 {
  if (angle > 0 && angle < M_PI)
   return (1);
 }
 else if (c == 'y')
 {
  if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
   return (1);
 }
 return (0);
}

int inter_check(float angle, float *inter, float *step, int is_horizon ,int TILE_SIZE)
{
 if (is_horizon)
 {
  if (angle > 0 && angle < M_PI)
  {
   *inter += TILE_SIZE;
   return (-1);
  }
  *step *= -1;
 }
 else
 {
  if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
  {
   *inter += TILE_SIZE;
   return (-1);
  }
  *step *= -1;
 }
 return (1);
}

t_intersection get_h_inter(t_data *data, t_rays *ray) 
{
 float h_x;
 float h_y;
 float x_step;
 float y_step;
 int  pixel;
        int TILE_SIZE = data->map->unit;
    t_intersection intersection = {0};

float angl = ray->angle;
 y_step = TILE_SIZE;
 x_step = TILE_SIZE / tan(angl);
 float variable = data->player->player_x;
 h_y = floor(data->player->player_y / TILE_SIZE) * TILE_SIZE;
 pixel = inter_check(angl, &h_y, &y_step, 1,TILE_SIZE);
 h_x = data->player->player_x + (h_y - data->player->player_y) / tan(angl);
 if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0))
  x_step *= -1;
 while (has_wall_at(data,h_x, h_y - pixel)) 
 {
  h_x += x_step;
  h_y += y_step;
 }
 intersection.x_intercept = h_x;
intersection.y_intercept = h_y;
 intersection.distance = sqrt(pow(h_x - data->player->player_x, 2) + pow(h_y - data->player->player_y, 2));
 return(intersection);
}

t_intersection get_v_inter(t_data *data, t_rays *ray)
{
 float v_x;
 float v_y;
 float x_step;
 float y_step;
 int  pixel;
int TILE_SIZE = data->map->unit;
t_intersection intersection = {0};

float angl = ray->angle;
 x_step = TILE_SIZE; 
 y_step = TILE_SIZE * tan(angl);
 v_x = floor(data->player->player_x / TILE_SIZE) * TILE_SIZE;
 float variable = data->player->player_x;
 pixel = inter_check(angl, &v_x, &x_step, 0,TILE_SIZE); 
 v_y = data->player->player_y + (v_x - data->player->player_x) * tan(angl);
 if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0))
  y_step *= -1;
 while (has_wall_at(data,v_x - pixel, v_y))
 {
  v_x += x_step;
  v_y += y_step;
 }
intersection.x_intercept = v_x;
intersection.y_intercept = v_y;
 intersection.distance =  sqrt(pow(v_x - data->player->player_x, 2) + pow(v_y - data->player->player_y, 2));
 return intersection;
}

void cast_ray(t_data *data, t_rays *ray) 
{
    ray->horizontal = get_h_inter(data, ray);
    ray->virtical = get_v_inter(data, ray);
    if(ray->virtical.distance <= ray->horizontal.distance )
    {   
        ray->x = ray->virtical.x_intercept;
        ray->y = ray->virtical.y_intercept;
        ray->distance = ray->virtical.distance;
        ray->flag = 1;
    }
    else
    {
        ray->x = ray->horizontal.x_intercept;
        ray->y = ray->horizontal.y_intercept;
        ray->distance = ray->horizontal.distance;
    }
    // render_ray(data, ray);
}



void stream_camera(t_data *data, t_rays *ray, int ray_id)
{


    ray->distance *= cos(normalize_angle(ray->angle - data->player->rotation_angel));
    data->vars->wall_h = (data->map->unit / ray->distance) * ((S_W / 2) / tan(data->player->FOV_angle / 2));
    data->vars->strip_wall_h = floor(data->vars->wall_h);
    data->vars->start_pix = (S_H / 2) - (data->vars->wall_h / 2);
    data->vars->end_pix = (S_H / 2) + (data->vars->wall_h / 2);
    data->vars->start_pix = fmax(0, data->vars->start_pix);
    data->vars->end_pix = fmin(S_H, data->vars->end_pix);
    if(ray->flag == 1)
        data->vars->offset_x = (int)ray->y % data->map->unit;
    else 
        data->vars->offset_x = (int)ray->x % data->map->unit;
    while(data->vars->start_pix < data->vars->end_pix)
    {
        int distance_from_top = (int)data->vars->start_pix - ((S_H / 2) - (data->vars->strip_wall_h / 2));
        data->vars->offset_y = distance_from_top * ((float)data->mlx->wall->height / data->vars->strip_wall_h);
        int color = get_color_at_position(data->mlx->wall, data->vars->offset_x, data->vars->offset_y);
        mlx_put_pixel(data->mlx->img, ray_id, data->vars->start_pix, color);
        data->vars->start_pix++;
    }
}


void ray_casting(t_data *data) 
{
    double ray_angle = data->player->rotation_angel - (data->player->FOV_angle / 2);
    int i = 0;
    while (i < data->player->num_rays) 
    {
        data->player->rays[i].angle = normalize_angle(ray_angle);
        cast_ray(data, &data->player->rays[i]);
        stream_camera(data, &data->player->rays[i], i);
        data->player->rays[i].flag = 0;
        ray_angle += (data->player->FOV_angle / data->player->num_rays);
        i++;
    }
}
