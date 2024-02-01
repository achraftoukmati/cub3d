/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:32:25 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/29 17:46:55 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sing;
	int	res;

	i = 0;
	sing = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sing *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sing);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     char s[]="   \n -6655  64568";
//     printf("%d\n",ft_atoi(s));
//     printf("%d\n",atoi(s));
// }