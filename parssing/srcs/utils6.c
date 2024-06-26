/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:16:35 by alotfi            #+#    #+#             */
/*   Updated: 2024/03/30 20:27:43 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	check_map(t_game *glo)
{
	int	i;
	int	j;
	int	w;

	i = 0;
	j = 0;
	w = 0;
	while (glo->map_ptr[j])
		j++;
	while (glo->map_ptr[i] && i < 1)
	{
		if (ft_fchecker(glo->map_ptr[i], '1', 32) == 1
			|| ft_fchecker(glo->map_ptr[j - 1], '1', 32) == 1)
			ft_rr("UNVALID_MAP1 \n");
		i++;
	}
	while (glo->map_ptr[w])
	{
		if (weet(glo->map_ptr[w]) == 0 || weet2(glo->map_ptr[w]) == 0)
			ft_rr("UNVALID_MAP2 \n");
		w++;
	}
}

int	kama(char *str)
{
	int	i;
	int	k_c;

	i = 0;
	k_c = 0;
	while (str && str[i])
	{
		if (str[i] == ',')
			k_c++;
		if (str[i] == ',' && str[i + 1] == ',')
			return (1);
		if (str[i] == ',' && str[i + 1] == '\0')
			return (1);
		i++;
	}
	if (k_c != 2)
		return (1);
	return (0);
}

int	ft_kama(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == 'F')
		{
			i++;
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i] == ',')
				return (1);
		}
		i++;
	}
	return (0);
}

t_counters	pssss(void)
{
	t_counters	ps;

	ps.i = 0;
	ps.no_c = 0;
	ps.so_c = 0;
	ps.we_c = 0;
	ps.ea_c = 0;
	ps.f_c = 0;
	ps.c_c = 0;
	return (ps);
}

void	ptr_check(t_game *glo)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (glo->f_s[i] && glo->c_s[j])
	{
		if (!is_number(glo->f_s[i]) || !is_number(glo->c_s[j]))
			ft_rr("NUMERIC_ARGUMENT_REQUIRED ❌\n");
		i++;
		j++;
	}
	if (!(ft_atoi(glo->f_s[1]) <= 255 && ft_atoi(glo->f_s[2]) <= 255
			&& ft_atoi(glo->f_s[3]) <= 255) || !(ft_atoi(glo->c_s[1]) <= 255
			&& ft_atoi(glo->c_s[2]) <= 255 && ft_atoi(glo->c_s[3]) <= 255))
		ft_rr("DO_NOT_EXCEED_255 ❌\n");
	weet3(glo);
}
