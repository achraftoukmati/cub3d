/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:24 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 17:37:13 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_press(void *dt)
{
	t_data	*data;

	data = dt;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
		data->player->turn_diraction = 1;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
		data->player->turn_diraction = -1;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_W))
		data->player->walk_diraction = 1;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_A))
		data->player->walk_lr_diraction = -1;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
		data->player->walk_diraction = -1;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_D))
		data->player->walk_lr_diraction = 1;
}
