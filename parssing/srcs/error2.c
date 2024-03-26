/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:02:27 by alotfi            #+#    #+#             */
/*   Updated: 2024/03/26 00:31:57 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	split_map(char *map)
{
	char	*start;
	int		i;

	start = NULL;
	i = 0;
	if (map)
		start = ft_strnstr(map, "1", ft_strlen(map));
	while (start && start[i])
	{
		if (start[i] == '\n' && start[i + 1] == '\n')
		{
			while (start[i])
			{
				if (start[i] != '\n')
				{
					free(map);
					ft_rr("SPLITED_MAP ❌\n");
				}
				i++;
			}
		}
		i++;
	}
}

void	ft_rr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] &&	s2[i] && s1[i] == s2[i])
	{
		i++;
		j++;
	}
	if (s1[i] == s2[i])
		return (0);
	else 
		return (1);
}

void	gook(t_game *glo)
{
    int i = 0;
    int j = 0;
    int counter = 0;
    int flag = 0;

    while (glo->map[i])
    {
        j = 0;
        while (glo->map[i][j])
        {
            if ( ft_strchr("N",glo->map[i][j]))
            {
                printf("-->%c<---\n", glo->map[i][j]);
                counter++;
            }
            if (glo->map[i][j] == 'N' && glo->map[i][j + 1] == '1')
            {
                flag = 1;
            }
            j++;
        }
        i++;
    }
    if (counter > 1  &&  flag == 0)
    ft_rr ("ERROR 02\n");
}
