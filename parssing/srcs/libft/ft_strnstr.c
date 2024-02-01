/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:10:51 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/29 17:55:29 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*src;
	char	*dest;
	int		j;

	i = 0;
	src = (char *)haystack;
	dest = (char *)needle;
	if (dest[0] == '\0')
		return (src);
	while (src[i] && i < len)
	{
		j = 0;
		while (src[i + j] == dest[j] && i + j < len)
		{
			if (dest[j + 1] == '\0')
				return (&src[i]);
			else
				j++;
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
//     char src[]="RIBMZPRIMZIBMZE123";
//     char dst[]="x";

//     printf("%s\n", strnstr("lorem ipsum dolor sit amet", "dolor", 15));
//     printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
// }
