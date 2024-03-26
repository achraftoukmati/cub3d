/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:00:51 by alotfi            #+#    #+#             */
/*   Updated: 2024/03/26 00:34:41 by alotfi           ###   ########.fr       */
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
	glo->NO_s = ft_split(glo->NO, 32, '\t');
	glo->SO_s = ft_split(glo->SO, 32, '\t');
	glo->WE_s = ft_split(glo->WE, 32, '\t');
	glo->EA_s = ft_split(glo->EA, 32, '\t');
	glo->F_s = ft_split(glo->F, 32, ',');
	glo->C_s = ft_split(glo->C, 32, ',');
}

void	syntax_check03(t_game *glo)
{
	splited_ptrs(glo);
	if (!ft_strnstr(glo->NO_s[1], ".png", ft_strlen(glo->NO_s[1]))
		|| !ft_strnstr(glo->SO_s[1], ".png", ft_strlen(glo->SO_s[1]))
		|| !ft_strnstr(glo->WE_s[1], ".png", ft_strlen(glo->WE_s[1]))
		|| !ft_strnstr(glo->EA_s[1], ".png", ft_strlen(glo->EA_s[1])))
		ft_rr("PNG FORMAT ONLY \n");
}

void	syntax_check(t_game *glo)
{
	splited_ptrs(glo);
	if (table_counter(glo->NO_s) != 2 || table_counter(glo->SO_s) != 2
		|| table_counter(glo->WE_s) != 2 || table_counter(glo->EA_s) != 2)
		ft_rr("SYNTAX_ERROR ❌\n");
	if (table_counter(glo->F_s) != 4 || table_counter(glo->C_s) != 4)
		ft_rr("SYNTAX_ERROR ❌\n");
	if (kama(glo->F) == 1 || kama(glo->C) == 1 || ft_kama(glo->C) == 1
		|| ft_kama(glo->F) == 1)
		ft_rr("SYNTAX_ERROR ❌\n");
	if (ft_strcmp(glo->NO_s[0], "NO") || ft_strcmp(glo->SO_s[0], "SO")
		|| ft_strcmp(glo->WE_s[0], "WE") || ft_strcmp(glo->EA_s[0], "EA"))
		ft_rr("SYNTAX_ERROR1 ❌\n");
	if (ft_strcmp(glo->F_s[0], "F") || ft_strcmp(glo->C_s[0], "C"))
		ft_rr("SYNTAX_ERROR2 ❌\n");
	syntax_check2(glo);
	ptr_check(glo);
	syntax_check03(glo);
}

void	syntax_check2(t_game *glo)
{
	if (open(glo->NO_s[1], O_RDONLY) == -1)
		ft_rr("UNVALID_PATH_TEXTURE ❌\n");
	if (open(glo->SO_s[1], O_RDONLY) == -1)
		ft_rr("UNVALID_PATH_TEXTURE ❌\n");
	if (open(glo->WE_s[1], O_RDONLY) == -1)
		ft_rr("UNVALID_PATH_TEXTURE ❌\n");
	if (open(glo->EA_s[1], O_RDONLY) == -1)
		ft_rr("UNVALID_PATH_TEXTURE ❌\n");
}
