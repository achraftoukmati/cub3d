/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:26:24 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/28 23:33:08 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = dstsize;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (!dest && dstsize == 0)
		return (src_len);
	while (*dest != '\0')
	{
		dest++;
		if (i > 0)
			i--;
	}
	while (*src != '\0' && i > 1)
	{
		*dest++ = *src++;
		i--;
	}
	*dest = '\0';
	if (dstsize > dest_len)
		return (dest_len + src_len);
	return (dstsize + src_len);
}
// #include <stdio.h>
// #include <strings.h>

// int main()
// {
//     char dest[10]="ayoub\0";
//     char src[10]="lotfi\0";

//     printf("%zu\n", ft_strlcat(dest,src, 3));
//     printf("%s\n", dest);
//     printf("%zu\n", strlcat(dest,src, 3));
//     printf("%s\n", dest);

// }