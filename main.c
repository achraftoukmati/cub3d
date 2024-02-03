/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:12:05 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/03 17:07:16 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./graphic/cub3d.h"
#include "./parssing/headers/cub3d.h"
#include "./libft/libft.h"

int init_player(t_data *data)
{
    data->player->radius = 3;
    data->player->player_x = locat_player(data->map->map,'X');
    data->player->player_y = locat_player(data->map->map,'Y');
    data->player->move_speed = 8;
    data->player->rotation_angel = M_PI / 2;
    data->player->walk_diraction = 0;
    data->player->turn_diraction = 0;
    data->player->rotation_speed = 5 * (M_PI / 180);
    data->player->FOV_angle = 60 * (M_PI / 180);
    data->player->wall_strip_width = 1;
    data->player->num_rays = S_W;
    data->player->rays = malloc(sizeof(t_rays) * (data->player->num_rays + 1));
    return (0);
}

int max_w(char **map)
{
    int w = 0;
    int i = 0;
    while(map[i])
    {
        if(ft_strlen(map[i]) > w)
            w = ft_strlen(map[i]);
        i++;
    }
    return w - 1;
}

int max_h(char **map)
{
    int h = 0;
    while(map[h])
        h++;
    return h - 1;
}

// char **correct_map(char **old_map)
// {
//     char **map;
    
    
// }

int init_map(t_map *data , t_game *ayoub)
{    

    // data->map = ayoub->map;
    int i = 0;
    while(ayoub->map_ptr[i])
    {
        printf("%s %d \n",ayoub->map_ptr[i],ayoub->map_ptr[i][0]);
        i++;
    }
    printf("%s\n",ayoub->SO);
    data->map = ayoub->map_ptr;
    data->map_height = max_h(data->map);
    data->map_width = max_w(data->map);
    data->unit = 80;
    data->ea = ayoub->EA_s[1];
    data->no = ayoub->NO_s[1];
    data->so = ayoub->SO_s[1];
    data->we = ayoub->WE_s[1];
    data->angle = 0.0f;
    return (0);
}

int init(t_data *data , t_game *ayoub)
{
    data->map = malloc(sizeof(t_map));
    init_map(data->map ,ayoub);
    data->player = malloc(sizeof(t_player));
    init_player(data);
    data->mlx = malloc(sizeof(t_mlx));
    data->vars = malloc(sizeof(t_rays));
    return 0;
}

void leaks_()
{
   system("leaks cub"); 
}

void free_all(t_data *data)
{
    int i = 0;
    // while(data->map->map[i])
    // {
    //     free(data->map->map[i]);
    //     i++;
    // }
    // free(data->map->map);
    if(data->map)
        free(data->map);
    if(data->player->rays)
        free(data->player->rays);
    if(data->player)
        free(data->player);
    if(data->mlx)
        free(data->mlx);
    if(data->vars)
        free(data->vars);
}


void exiting(t_data *data,int var)
{
    mlx_delete_image(data->mlx->mlx, data->mlx->img);
    mlx_close_window(data->mlx->mlx);
    mlx_terminate(data->mlx->mlx);
    mlx_delete_texture(data->mlx->EA);
    mlx_delete_texture(data->mlx->SO);
    mlx_delete_texture(data->mlx->NO);
    mlx_delete_texture(data->mlx->WE);
    free_all(data);
    leaks_();
    if(var != ERROR)
        printf("Game closed!\n");
    exit(var);
}

int main(int ac, char **av)
{
    t_game	glo;
	int		i;

	if (ac != 2)
	{
		ft_rr("UNVALID_INPUT 😨\n");
	}
    t_data data;
	glo.map_name = av[1];
	cub_all(&glo);
	chkeck_player(&glo);
    init(&data,&glo);
    start_game(&data);
    exiting(&data,0);
    return 0;
}
