/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:40:16 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/21 18:43:37 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#endif

typedef struct e_colors
{
	int F[3];
	int C[3];
	
} t_colors;

typedef struct s_game
{
	t_colors colors;
	char	*map_name;
	int		fd;
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	**NO_s;
	char	**SO_s;
	char	**WE_s;
	char	**EA_s;
	char	**F_s;
	char	**C_s;
	char	**map_ptr;
}			t_game;

typedef struct s_counters
{
	int		i;
	int		no_c;
	int		so_c;
	int		we_c;
	int		ea_c;
	int		f_c;
	int		c_c;
}			t_counters;

typedef struct s_varcall
{
	int		i;
	int		nc;
	int		sc;
	int		wc;
	int		ec;
}			t_varcall;

void		check_under_zero(t_game *glo);
int			ft_fchecker(char *str, char c, char w);
void		check_map(t_game *glo);
int			table_counter(char **tab);
char		*ftt_strncpy(char *s1, char *s2, int n);
char		**ftt_split(char *str, char c, char w);
int			is_number(char *str);
int			check_map_name(char *str);
void		empty_fillxx(t_game *glo);
void		read_map(t_game *glo);
void		get_ptrs(t_game *glo);
int			weet(char *str);
int			weet2(char *str);
void weet3(t_game *glo);
// int			f_check(char *str);
void		valid_path(t_game *glo);
int			kama(char *str);
int			ft_kama(char *str);
void		syntax_check(t_game *glo);
void		ft_check_map(t_game *glo);
void		ft_check_map2(t_game *glo);
void		check_under_zero(t_game *glo);
void		cub_all(t_game *glo);
int			my_cont(char *s, char c);
int			ft_checknl(char *str);
char		*get_firstline(char *str);
char		*get_afterline(char *str);
char		*read_fd(int fd, char *str);
char		*get_next_line(int fd);
void		get_map(t_game *glo);
// void	ft_check_map3(t_game *glo);
// int			f_check1(char *str);
// int			f_check2(char *str);
void		syntax_check2(t_game *glo);
void		ptr_check(t_game *glo);
t_counters	pssss(void);
void		get_ptrs2(t_game *glo);
void		splited_map(t_game *glo);
void		split_map(char *map);
void		ft_check_map3(t_game *glo);
void		chkeck_player(t_game *glo);

// ERROR CHECK
void		ft_rr(char *str);
int			one_only_one(char *str );
void		check_pp1(t_game *glo);
void		play_pos(t_game *glo);
int			ft_strcmp(char *s1, char *s2);
void		check_pp(t_game *glo);
void		kechma(t_game *glo);
int			ger(char *str);
int			ger1(char *str);