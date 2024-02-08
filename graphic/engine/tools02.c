/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:26:13 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 18:40:07 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_all(t_data *data)
{
	if (data->map)
		free(data->map);
	if (data->player->rays)
		free(data->player->rays);
	if (data->player)
		free(data->player);
	if (data->mlx)
		free(data->mlx);
	if (data->vars)
		free(data->vars);
}

void	mlx_end(t_data *data)
{
	mlx_delete_image(data->mlx->mlx, data->mlx->img);
	mlx_close_window(data->mlx->mlx);
	mlx_terminate(data->mlx->mlx);
	mlx_delete_texture(data->mlx->ea);
	mlx_delete_texture(data->mlx->so);
	mlx_delete_texture(data->mlx->no);
	mlx_delete_texture(data->mlx->we);
}

void	exiting(t_data *data, int var)
{
	mlx_end(data);
	free_all(data);
	if (var != ERROR)
		printf("Game closed!\n");
	exit(var);
}

int	max_w(char **map)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > w)
			w = ft_strlen(map[i]);
		i++;
	}
	return (w - 1);
}

int	max_h(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h - 1);
}
