/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:53:11 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/29 17:50:27 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dst;
	if (!s && !d)
		return (NULL);
	if (s == d)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
// #include <string.h>
//  int main()
//  {
//      char dst[]="ayoubhh";
//      char src[]="aaaaa";
//      char dst1[]="ayoubhh";
//      char src1[]="aaaaa";

//      printf("%s\n", memcpy(dst1, src1, 5));
//      printf("%s\n", ft_memcpy(dst, src, 5));
//  }
