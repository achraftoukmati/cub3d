/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:43:29 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 18:21:14 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	unit_circle(float angle, char c)
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

int	inter_check(t_rays *ray, float *inter, float *step, int unit)
{
	if (ray->flag)
	{
		if (ray->angle > 0 && ray->angle < M_PI)
		{
			*inter += unit;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(ray->angle > M_PI / 2 && ray->angle < 3 * M_PI / 2))
		{
			*inter += unit;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

mlx_texture_t	*get_wall_texture(t_rays *ray, t_mlx *mlx)
{
	if (ray->flag == 1)
	{
		if (sin(ray->angle) > 0)
			return (mlx->so);
		return (mlx->ea);
	}
	if (cos(ray->angle) > 0)
		return (mlx->no);
	return (mlx->we);
}
