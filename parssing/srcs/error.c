/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:53:26 by alotfi            #+#    #+#             */
/*   Updated: 2024/02/19 19:51:20 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../headers/cub3d.h"

#include "../headers/cub3d.h"


void mektr(t_game * glo);
void check_pp(t_game *glo)
{
    int i = 0;
    int j = 0;
    int flag;
    flag = 0;

    while(glo->map[i])
    {
        j = 0;
        while(glo->map[i][j])
        {
            if(!ft_strchr("NSWEFC1 ", glo->map[i][0]))
            {
                printf("---->OOK<-----\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
    check_pp1(glo);
    play_pos(glo);
}

int one_only_one(char *str )
{
    int i = 0;

    while(str && str[i])
    {
        if(str[i] == '1' || str[i] == 32)
            i++;
        else 
        return 1;
    }
    return 0;
}

int ft_plyer_poss(char *s)
{
    int i = 0;

    while(s && s[i])
    {
        if(s[i] == 'S' || s[i] == 'W' || s[i] == 'P' || s[i] == 'N' || s[i] == '0')
        {
            if(s[i + 1] == 32 || s[i - 1] == 32)
            return 1;
        }
        i++;
    }
    return 0;
}

void play_pos(t_game *glo)
{
    int i = 0;
    int j = 0;
    int w = 0;
    
    while(glo->map_ptr[i])
    {
        j = 0;
        while(glo->map_ptr[i][j])
        {
            if(ft_plyer_poss(&glo->map_ptr[i][j]) == 1 )
                ft_rr("NOT_A_VALID_PATH3 ❌\n");
            if(ft_strchr("WSEN0", glo->map_ptr[i][j]))
            {
                w = j;
                if(ft_strchr(" ", glo->map_ptr[i - 1][w]) || ft_strchr(" ", glo->map_ptr[i + 1][w]))
                    ft_rr("NOT_A_VALID_PATH2 ❌\n");
            }
            j++;
        }
        i++;
    }
    kechma(glo);
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
            if(ft_strchr("1", glo->map[i][0]) || ft_strchr(" ", glo->map[i][0])|| ft_strchr("   ", glo->map[i][0]))
            {
                if((one_only_one(&glo->map[i][j]) == 1 && flag != 1))
                ft_rr("--->ok<---- \n");
                if(ft_strchr("11", glo->map[i][j]))
                     flag = 1;
            }
            j++;
        }
        i++;
    }
}

//9lb 3la awl str 3amer wahdat
// nd map matkonch fiha smtg mn ghir SWPN01 
