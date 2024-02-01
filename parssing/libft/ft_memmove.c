/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:14:49 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/29 22:25:45 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst && !src)
	{
		return (NULL);
	}
	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (d > s)
	{
		while (n-- > i)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}

// int main ()
// {
//     char str[] = "jajjajaj";
//     char srr[] = "hshsh";
//     printf("%s", ft_memmove(srr,str,5));
//     printf("%s", memmove((void*)0,str,NULL));
// }
