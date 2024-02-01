/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:14:55 by alotfi            #+#    #+#             */
/*   Updated: 2022/11/01 01:41:52 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*x;

	i = 0;
	x = str;
	while (i < len)
	{
		x[i] = (char)c;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
//    char str[70] ="ayoooooooub";
//    ft_memset(str, 'k', 7);
//    printf("%s", str);
// }
