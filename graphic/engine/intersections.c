/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:50:53 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 18:22:07 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_intersection	get_h_inter(t_data *data, t_rays *ray)
{
	t_intersection	intersection;
	int				pixel;

	intersection.y_step = data->map->unit;
	intersection.x_step = data->map->unit / tan(ray->angle);
	intersection.y_intercept = floor(data->player->player_y / data->map->unit)
		* data->map->unit;
	ray->flag = 1;
	pixel = inter_check(ray, &intersection.y_intercept, &intersection.y_step,
			data->map->unit);
	intersection.x_intercept = data->player->player_x
		+ (intersection.y_intercept - data->player->player_y) / tan(ray->angle);
	if ((unit_circle(ray->angle, 'y') && intersection.x_step > 0)
		|| (!unit_circle(ray->angle, 'y') && intersection.x_step < 0))
		intersection.x_step *= -1;
	while (has_wall_at(data, intersection.x_intercept, intersection.y_intercept
			- pixel))
	{
		intersection.x_intercept += intersection.x_step;
		intersection.y_intercept += intersection.y_step;
	}
	intersection.distance = sqrt(pow(intersection.x_intercept
				- data->player->player_x, 2) + pow(intersection.y_intercept
				- data->player->player_y, 2));
	return (intersection);
}

t_intersection	get_v_inter(t_data *data, t_rays *ray)
{
	int				pixel;
	t_intersection	intersection;

	intersection.x_step = data->map->unit;
	intersection.y_step = data->map->unit * tan(ray->angle);
	intersection.x_intercept = floor(data->player->player_x / data->map->unit)
		* data->map->unit;
	ray->flag = 0;
	pixel = inter_check(ray, &intersection.x_intercept, &intersection.x_step,
			data->map->unit);
	intersection.y_intercept = data->player->player_y
		+ (intersection.x_intercept - data->player->player_x) * tan(ray->angle);
	if ((unit_circle(ray->angle, 'x') && intersection.y_step < 0)
		|| (!unit_circle(ray->angle, 'x') && intersection.y_step > 0))
		intersection.y_step *= -1;
	while (has_wall_at(data, intersection.x_intercept - pixel,
			intersection.y_intercept))
	{
		intersection.x_intercept += intersection.x_step;
		intersection.y_intercept += intersection.y_step;
	}
	intersection.distance = sqrt(pow(intersection.x_intercept
				- data->player->player_x, 2) + pow(intersection.y_intercept
				- data->player->player_y, 2));
	return (intersection);
}
