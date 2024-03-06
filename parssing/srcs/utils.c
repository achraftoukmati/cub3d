/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:49:19 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/22 16:24:31 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	empty_fillxx(t_game *glo)
{
	int		x;
	char	*tmp;

	x = open(glo->map_name, O_RDONLY);
	tmp = ft_calloc(2, 1);
	read(x, tmp, 1);
	if (tmp[0] == '\0')
		ft_rr("UNVALID_MAP_NAME ❌\n");
	else
	{
		free(tmp);
		close(x);
	}
}

void	read_map(t_game *glo)
{
	char	*line;
	char	*all;

	empty_fillxx(glo);
	if (check_map_name(glo->map_name) == 0)
		ft_rr("UNVALID_MAP_NAME ❌\n");
	glo->fd = open(glo->map_name, O_RDONLY);
	if (glo->fd == -1)
		ft_rr("UNVALID_MAP_NAME ❌\n");
	all = NULL;
	while (1)
	{
		line = get_next_line(glo->fd);
		if (!line)
			break ;
		all = ft_str_join(all, line);
		free(line);
	}
	split_map(all);
	glo->map = ft_split(all, '\n', '\n');
	free(all);
}

void	get_map(t_game *glo)
{
	int	i;

	i = 0;
	while (glo->map[i] && ger1 (glo->map_ptr[i]) == 1)
		i++;
	if (glo->map[i] == NULL)
		ft_rr("I_THINK_YOU_FORGOT_A_MAP1 🤓\n");
	glo->map_ptr = &glo->map[i];
	// if (glo->map_ptr[i] == NULL)
	// 	ft_rr("I_THINK_YOU_FORGOT_A_MAP2 🤓\n");
}

void	get_ptrs(t_game *glo)
{
	t_counters	ps;

	ps = pssss();
	while (glo->map[ps.i])
	{
		if (ft_strnstr(glo->map[ps.i], "EA", ft_strlen(glo->map[ps.i])))
		{
			glo->EA = glo->map[ps.i];
			ps.ea_c++;
		}
		else if (ft_strnstr(glo->map[ps.i], "F", ft_strlen(glo->map[ps.i])))
		{
			glo->F = glo->map[ps.i];
			ps.f_c++;
		}
		else if (ft_strnstr(glo->map[ps.i], "C", ft_strlen(glo->map[ps.i])))
		{
			glo->C = glo->map[ps.i];
			ps.c_c++;
		}
		ps.i++;
	}
	if (ps.ea_c != 1 || ps.f_c != 1 || ps.c_c != 1)
		ft_rr("NOT_A_VALID_PATH1 ❌\n");
	glo->map_ptr = glo->map;
}

void	get_ptrs2(t_game *glo)
{
	t_counters	ph;

	ph = pssss();
	while (glo->map[ph.i])
	{
		if (ft_strnstr(glo->map[ph.i], "NO", ft_strlen(glo->map[ph.i])))
		{
			glo->NO = glo->map[ph.i];
			ph.no_c++;
		}
		else if (ft_strnstr(glo->map[ph.i], "SO", ft_strlen(glo->map[ph.i])))
		{
			glo->SO = glo->map[ph.i];
			ph.so_c++;
		}
		else if (ft_strnstr(glo->map[ph.i], "WE", ft_strlen(glo->map[ph.i])))
		{
			glo->WE = glo->map[ph.i];
			ph.we_c++;
		}
		ph.i++;
	}
	if (ph.no_c != 1 || ph.so_c != 1 || ph.we_c != 1)
		ft_rr("NOT_A_VALID_PATH4 ❌\n");
	get_map(glo);
}
