/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:53:26 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/13 14:33:43 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void check_pp1(t_game *glo);

void check_pp(t_game *glo)
{
    int i = 0;
    int j = 0;


    while(glo->map[i])
    {
        j = 0;
        while(glo->map[i][j])
        {
            if(!ft_strchr("NSWEFC1 ", glo->map[i][0]))
            {
                printf("---->OK<-----\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
    check_pp1(glo);
}

int one_only_one(char *str )
{
    int i = 0;

    while(str && str[i])
    {
        if(str[i] == '1' || str[i] == ' ')
            i++;
        else 
        return 1;
    }
    return 0;
}

void check_pp1(t_game *glo)
{
    int i = 0;
    int j = 0;
    int flag = 0;

    while(glo->map[i])
    {
        j = 0;
        while(glo->map[i][j])
        {
            if(ft_strchr("1", glo->map[i][0]))
            {
                if(one_only_one(&glo->map[i][j]) == 1 && flag != 1)
                {
                    printf("---->OK<-----\n");
                    exit(1);
                }
                if(ft_strchr("111", glo->map[i][j]))
                     flag = 1;
            }
            j++;
        }
        i++;
    }
}