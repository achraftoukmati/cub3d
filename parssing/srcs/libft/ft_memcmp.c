/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:38:15 by alotfi            #+#    #+#             */
/*   Updated: 2022/11/01 01:41:32 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char s1[]="abcd";
//     char s2[]="abfd";

//     printf("%d\n", memcmp(s1, s2, 4));
//     printf("%d\n", ft_memcmp(s1, s2, 4));

// }