/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:14:30 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 18:19:44 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cast_ray(t_data *data, t_rays *ray)
{
	ray->horizontal = get_h_inter(data, ray);
	ray->virtical = get_v_inter(data, ray);
	if (ray->virtical.distance <= ray->horizontal.distance)
	{
		ray->x = ray->virtical.x_intercept;
		ray->y = ray->virtical.y_intercept;
		ray->distance = ray->virtical.distance;
		ray->flag = 1;
	}
	else
	{
		ray->flag = 0;
		ray->x = ray->horizontal.x_intercept;
		ray->y = ray->horizontal.y_intercept;
		ray->distance = ray->horizontal.distance;
	}
}

void	put_line_on_the_screen(t_data *data, t_rays *ray)
{
	int	distance_from_top;
	int	color;

	distance_from_top = (int)data->vars->start_pix - ((S_H / 2)
			- (data->vars->strip_wall_h / 2));
	data->vars->offset_y = distance_from_top * ((float)data->mlx->wall->height
			/ data->vars->strip_wall_h);
	color = get_color_at_position(data->mlx->wall, data->vars->offset_x,
			data->vars->offset_y);
	mlx_put_pixel(data->mlx->img, ray->ray_id, data->vars->start_pix, color);
	data->vars->start_pix++;
}

void	stream_camera(t_data *data, t_rays *ray)
{
	ray->distance *= cos(normalize_angle(ray->angle
				- data->player->rotation_angel));
	data->vars->wall_h = (data->map->unit / ray->distance) * ((S_W / 2)
			/ tan(data->player->fov_angle / 2));
	data->vars->strip_wall_h = floor(data->vars->wall_h);
	data->vars->start_pix = (S_H / 2) - (data->vars->wall_h / 2);
	data->vars->end_pix = (S_H / 2) + (data->vars->wall_h / 2);
	data->vars->start_pix = fmax(0, data->vars->start_pix);
	data->vars->end_pix = fmin(S_H, data->vars->end_pix);
	if (ray->flag == 1)
		data->vars->offset_x = (int)ray->y % data->map->unit;
	else
		data->vars->offset_x = (int)ray->x % data->map->unit;
	data->mlx->wall = get_wall_texture(ray, data->mlx);
	while (data->vars->start_pix < data->vars->end_pix)
		put_line_on_the_screen(data, ray);
}

void	ray_casting(t_data *data)
{
	double	ray_angle;
	int		i;

	ray_angle = data->player->rotation_angel - (data->player->fov_angle / 2);
	i = 0;
	while (i < data->player->num_rays)
	{
		data->player->rays[i].angle = normalize_angle(ray_angle);
		data->player->rays[i].ray_id = i;
		cast_ray(data, &data->player->rays[i]);
		stream_camera(data, &data->player->rays[i]);
		data->player->rays[i].flag = 0;
		ray_angle += (data->player->fov_angle / data->player->num_rays);
		i++;
	}
}
