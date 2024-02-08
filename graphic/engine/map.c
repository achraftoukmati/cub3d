/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:20:20 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 17:41:32 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_color(char cell)
{
	if (cell == '1')
		return (BLUE);
	else if (cell == '0')
		return (WHITE);
	else if (cell == 'P')
		return (WHITE);
	else
		return (-1);
}

void	fill_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < S_W)
	{
		j = 0;
		while (j < S_H)
		{
			if (j < (S_H / 2))
				mlx_put_pixel(data->mlx->img, i, j, data->mlx->floor);
			else
				mlx_put_pixel(data->mlx->img, i, j, data->mlx->celling);
			j++;
		}
		i++;
	}
}

void	update_map(t_data *data)
{
	mlx_delete_image(data->mlx->mlx, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->mlx, S_W, S_H);
	fill_map(data);
}
