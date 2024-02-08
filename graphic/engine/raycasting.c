/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:14:30 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 17:24:53 by atoukmat         ###   ########.fr       */
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

int inter_check(float angle, float *inter, float *step, int is_horizon ,int unit)
{
 if (is_horizon)
 {
  if (angle > 0 && angle < M_PI)
  {
   *inter += unit;
   return (-1);
  }
  *step *= -1;
 }
 else
 {
  if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
  {
   *inter += unit;
   return (-1);
  }
  *step *= -1;
 }
 return (1);
}

t_intersection get_h_inter(t_data *data, t_rays *ray) 
{

t_intersection intersection = {0};
 int  pixel;
 intersection.y_step = data->map->unit;
 intersection.x_step = data->map->unit / tan(ray->angle);
intersection.y_intercept = floor(data->player->player_y / data->map->unit) * data->map->unit;
 pixel = inter_check(ray->angle, & intersection.y_intercept, &intersection.y_step, 1,data->map->unit);
  intersection.x_intercept = data->player->player_x + ( intersection.y_intercept - data->player->player_y) / tan(ray->angle);
 if ((unit_circle(ray->angle, 'y') && intersection.x_step > 0) || (!unit_circle(ray->angle, 'y') && intersection.x_step < 0))
  intersection.x_step *= -1;
 while (has_wall_at(data, intersection.x_intercept,  intersection.y_intercept - pixel)) 
 {
   intersection.x_intercept += intersection.x_step;
   intersection.y_intercept += intersection.y_step;
 }
 intersection.distance = sqrt(pow( intersection.x_intercept - data->player->player_x, 2) + pow( intersection.y_intercept - data->player->player_y, 2));
 return(intersection);
}

t_intersection get_v_inter(t_data *data, t_rays *ray)
{
 int  pixel;
t_intersection intersection = {0};
 intersection.x_step = data->map->unit; 
 intersection.y_step = data->map->unit * tan(ray->angle);
 intersection.x_intercept = floor(data->player->player_x / data->map->unit) * data->map->unit;
 pixel = inter_check(ray->angle, &intersection.x_intercept, &intersection.x_step, 0,data->map->unit); 
 intersection.y_intercept = data->player->player_y + (intersection.x_intercept - data->player->player_x) * tan(ray->angle);
 if ((unit_circle(ray->angle, 'x') && intersection.y_step < 0) || (!unit_circle(ray->angle, 'x') && intersection.y_step > 0))
  intersection.y_step *= -1;
 while (has_wall_at(data,intersection.x_intercept - pixel, intersection.y_intercept))
 {
  intersection.x_intercept += intersection.x_step;
  intersection.y_intercept += intersection.y_step;
 }
 intersection.distance =  sqrt(pow(intersection.x_intercept - data->player->player_x, 2) + pow(intersection.y_intercept - data->player->player_y, 2));
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


mlx_texture_t *get_wall_texture(t_rays *ray,t_mlx *mlx)
{
    if(ray->flag == 1)
    {
        if(sin(ray->angle) > 0)
            return mlx->SO;
        return mlx->EA;
    
    }
    if(cos(ray->angle) > 0)
        return mlx->NO;
    return mlx->WE;
}

void stream_camera(t_data *data, t_rays *ray)
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
    data->mlx->wall = get_wall_texture(ray,data->mlx);
    while(data->vars->start_pix < data->vars->end_pix)
    {
        int distance_from_top = (int)data->vars->start_pix - ((S_H / 2) - (data->vars->strip_wall_h / 2));
        data->vars->offset_y = distance_from_top * ((float)data->mlx->wall->height / data->vars->strip_wall_h);
        int color = get_color_at_position(data->mlx->wall, data->vars->offset_x, data->vars->offset_y);
        mlx_put_pixel(data->mlx->img, ray->ray_id, data->vars->start_pix, color);
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
        data->player->rays[i].ray_id = i;
        cast_ray(data, &data->player->rays[i]);
        stream_camera(data, &data->player->rays[i]);
        data->player->rays[i].flag = 0;
        ray_angle += (data->player->FOV_angle / data->player->num_rays);
        i++;
    }
}
