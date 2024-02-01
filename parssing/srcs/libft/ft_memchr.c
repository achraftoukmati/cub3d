/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:46:34 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/31 22:19:16 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sr;

	i = 0;
	sr = (unsigned char *)s;
	while (i < n)
	{
		if (sr[i] == (unsigned char)c)
			return (&sr[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     // char src[]="ayoubzz";
//     // char c = 'o';
//     char *src = "/|\x12\xff\x09\0\x42\042\0\42|\\";
//  	int size = 12;

//    printf("%d\n", *(char *)memchr(src, '\0', size));
//     printf("%d\n", *(char *)ft_memchr(src, '\0', size));
// }