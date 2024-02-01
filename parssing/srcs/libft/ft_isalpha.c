/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:11:28 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/31 23:50:49 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main()
// {
//     char a ='z';
//     printf("%d\n", ft_isalpha(a));
//     printf("%d\n", isalpha(a));
// }