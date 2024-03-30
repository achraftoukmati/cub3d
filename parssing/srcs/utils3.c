/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:00:51 by alotfi            #+#    #+#             */
/*   Updated: 2024/03/30 20:33:45 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	valid_path(t_game *glo)
{
	int	i;
	int	w;
	int	j;

	i = 1;
	while (glo->map_ptr[i] != '\0' && glo->map_ptr[i + 1] != '\0')
	{
		j = 0;
		w = 0;
		while (glo->map_ptr[i][j] == 32)
			j++;
		while (glo->map_ptr[i][j])
		{
			if (ft_strchr(" ", glo->map_ptr[i][j]))
			{
				w = j;
				if ((glo->map_ptr[i - 1][w] != '1' && glo->map_ptr[i
						- 1][w] != 32))
					ft_rr("UNVALID_MAP \n");
			}
			j++;
		}
		i++;
	}
}

void	splited_ptrs(t_game *glo)
{
	glo->no_s = ft_split(glo->no, 32, '\t');
	glo->so_s = ft_split(glo->so, 32, '\t');
	glo->we_s = ft_split(glo->we, 32, '\t');
	glo->ea_s = ft_split(glo->ea, 32, '\t');
	glo->f_s = ft_split(glo->f, 32, ',');
	glo->c_s = ft_split(glo->c, 32, ',');
}

void	syntax_check03(t_game *glo)
{
	if (!ft_strnstr(glo->no_s[1], ".png", ft_strlen(glo->no_s[1]))
		|| !ft_strnstr(glo->so_s[1], ".png", ft_strlen(glo->so_s[1]))
		|| !ft_strnstr(glo->we_s[1], ".png", ft_strlen(glo->we_s[1]))
		|| !ft_strnstr(glo->ea_s[1], ".png", ft_strlen(glo->ea_s[1])))
		ft_rr("PNG FORMAT ONLY \n");
}

void	syntax_check(t_game *glo)
{
	splited_ptrs(glo);

	if (table_counter(glo->no_s) != 2 || table_counter(glo->so_s) != 2
		|| table_counter(glo->we_s) != 2 || table_counter(glo->ea_s) != 2)
		ft_rr("SYNTAX_ERROR ❌\n");
	if (table_counter(glo->f_s) != 4 || table_counter(glo->c_s) != 4)
		ft_rr("SYNTAX_ERROR ❌\n");
	if (kama(glo->f) == 1 || kama(glo->c) == 1 || ft_kama(glo->c) == 1
		|| ft_kama(glo->f) == 1)
		ft_rr("SYNTAX_ERROR ❌\n");
	if (ft_strcmp(glo->no_s[0], "NO") || ft_strcmp(glo->so_s[0], "SO")
		|| ft_strcmp(glo->we_s[0], "WE") || ft_strcmp(glo->ea_s[0], "EA"))
		ft_rr("SYNTAX_ERROR1 ❌\n");
	if (ft_strcmp(glo->f_s[0], "F") || ft_strcmp(glo->c_s[0], "C"))
		ft_rr("SYNTAX_ERROR2 ❌\n");
	syntax_check2(glo);

	ptr_check(glo);
	syntax_check03(glo);
}

void	syntax_check2(t_game *glo)
{
	if (open(glo->no_s[1], O_RDONLY) == -1)
		ft_rr("UNVALID_PATH_TEXTURE ❌\n");
	if (open(glo->so_s[1], O_RDONLY) == -1)
		ft_rr("UNVALID_PATH_TEXTURE ❌\n");
	if (open(glo->we_s[1], O_RDONLY) == -1)
		ft_rr("UNVALID_PATH_TEXTURE ❌\n");
	if (open(glo->ea_s[1], O_RDONLY) == -1)
		ft_rr("UNVALID_PATH_TEXTURE ❌\n");
}
