/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:15:08 by alotfi            #+#    #+#             */
/*   Updated: 2022/11/01 00:17:40 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	s;

	s = (char)c;
	while (*str != '\0')
	{
		if ((char)*str == s)
			return ((char *)str);
		str++;
	}
	if ((char)*str == s)
		return ((char *)str);
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char c1 = 'b';
//     char src1[40]="ayoublotfi";

//     printf(">%s<\n", ft_strchr(src1,c1));

//     printf(">%s<\n", strchr(src1,c1));
// }