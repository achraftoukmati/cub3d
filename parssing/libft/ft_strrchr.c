/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:15:34 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/29 17:55:34 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	while (s[len] != (char)c)
	{
		if (len == 0)
			return (0);
		len--;
	}
	return ((char *)&s[len]);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     char src[30]="";
//     char c ='.';

//     printf("%s\n",ft_strrchr(src, c));
//      printf("%s\n",strrchr(src, c));
//      return(0);
// }