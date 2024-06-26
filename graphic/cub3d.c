/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:12:00 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 17:32:09 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_keys(t_data *data)
{
	data->player->walk_diraction = 0;
	data->player->turn_diraction = 0;
	data->player->walk_lr_diraction = 0;
	mlx_image_to_window(data->mlx->mlx, data->mlx->img, 0, 0);
}

void	game_loop(void *data)
{
	update_map((t_data *)data);
	update_player((t_data *)data);
	ray_casting((t_data *)data);
	update_keys((t_data *)data);
}

void	escape(void *data)
{
	if (mlx_is_key_down(((t_data *)data)->mlx->mlx, MLX_KEY_ESCAPE))
		exiting((t_data *)data, 0);
}

int	init_mlx(t_data *data)
{
	data->mlx->ea = mlx_load_png(data->map->ea);
	data->mlx->no = mlx_load_png(data->map->no);
	data->mlx->so = mlx_load_png(data->map->so);
	data->mlx->we = mlx_load_png(data->map->we);
	if (!data->mlx->ea || !data->mlx->no || !data->mlx->so || !data->mlx->we)
		exiting(data, 2);
	return (0);
}

void	start_game(t_data *data)
{
	data->mlx->mlx = mlx_init(S_W, S_H, "cub", false);
	data->mlx->img = mlx_new_image(data->mlx->mlx, S_W, S_H);
	init_mlx(data);
	mlx_loop_hook(data->mlx->mlx, game_loop, data);
	mlx_loop_hook(data->mlx->mlx, escape, data);
	mlx_loop(data->mlx->mlx);
}
