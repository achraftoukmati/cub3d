/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoukmat <atoukmat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:58:07 by atoukmat          #+#    #+#             */
/*   Updated: 2024/02/08 18:34:23 by atoukmat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../mlx/MLX42/MLX42.h"
# include "../parssing/headers/cub3d.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define S_W 2000
# define S_H 1000

# define DARK_BLUE 191970
# define DARK_ORANGE 0x483C32
# define DARK_GREEN 0x3e00ed

# define ERROR 1
# define WHITE 0xFFFFFFFF
# define BLUE 0xFFFF
# define RED 0xFF0000FF
# define PURPLE 0xFF00FFFF
# define YELLOW 0xFFFF00FF
# define BLACK 0x00000000

# define GREEN 0x00FF00FF
# define ORANGE 0xFFA500FF
# define PINK 0xFF69B4FF
# define CYAN 0x00FFFFFF
# define GRAY 0x808080FF
# define BROWN 0xA52A2AFF

typedef struct s_map
{
	char			**map;
	char			*so;
	char			*no;
	char			*we;
	char			*ea;
	int				map_width;
	int				map_height;
	int				unit;
	float			angle;
}					t_map;

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*wall;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	int				floor;
	int				celling;

}					t_mlx;

typedef struct s_intersection
{
	double			distance;
	float			y_step;
	float			x_step;
	float			x_intercept;
	float			y_intercept;
}					t_intersection;

typedef struct s_vars
{
	double			wall_h;
	double			start_pix;
	double			end_pix;
	int				strip_wall_h;
	float			offset_x;
	float			offset_y;

}					t_vars;

typedef struct s_rays
{
	int				ray_id;
	int				flag;
	float			x;
	float			y;
	float			angle;
	double			distance;
	t_intersection	horizontal;
	t_intersection	virtical;
}					t_rays;

typedef struct s_player
{
	float			player_x;
	float			player_y;
	float			radius;
	int				turn_diraction;
	int				walk_diraction;
	int				walk_lr_diraction;
	float			rotation_angel;
	int				move_speed;
	float			rotation_speed;
	float			fov_angle;
	int				num_rays;
	int				wall_strip_width;
	int				move_step;
	int				strafe_step;
	float			n_x;
	float			n_y;
	t_rays			*rays;
}					t_player;

typedef struct s_data
{
	t_map			*map;
	t_player		*player;
	t_mlx			*mlx;
	t_vars			*vars;
}					t_data;
typedef struct s_game
{
	char			*map_name;
	int				fd;
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	char			**no_s;
	char			**so_s;
	char			**we_s;
	char			**ea_s;
	char			**f_s;
	char			**c_s;
	char			**map_ptr;
}					t_game;

void				cub_all(t_game *glo);
void				ft_rr(char *str);
void				chkeck_player(t_game *glo);

int					get_rgba(int r, int g, int b, int a);
int					get_color_at_position(mlx_texture_t *texture, int x, int y);
void				ray_casting(t_data *data);
void				update_map(t_data *data);
void				start_game(t_data *data);
void				game_loop(void *data);
void				key_press(void *dt);
void				fill_map(t_data *data);
int					get_color(char cell);
int					has_wall_at(t_data *data, float x, float y);
float				normalize_angle(float angle);
void				update_player(t_data *data);
int					locat_player(char **map, char target);
void				exiting(t_data *data, int var);
int					inter_check(t_rays *ray, float *inter, float *step,
						int unit);
int					unit_circle(float angle, char c);
t_intersection		get_h_inter(t_data *data, t_rays *ray);
t_intersection		get_v_inter(t_data *data, t_rays *ray);
mlx_texture_t		*get_wall_texture(t_rays *ray, t_mlx *mlx);
int					init_map(t_map *data, t_game *ayoub);
int					init_player(t_data *data);
int					max_w(char **map);
int					max_h(char **map);

void				mlx_end(t_data *data, int var);
void				free_all(t_data **data);
int					init(t_data *data, t_game *ayoub);
void				exiting(t_data *data, int var);

#endif