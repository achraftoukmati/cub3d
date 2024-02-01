/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:56:03 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/31 22:39:12 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*s2;
	size_t	len;

	if (!s1 || !set)
		return (0);
	str = (char *)s1;
	while (*str && ft_strchr((char *)set, *str))
		str++;
	len = ft_strlen((char *)str);
	if (len == 0)
		return (ft_substr("", 0, len));
	while (len && ft_strchr((char *)set, str[len]))
		len--;
	s2 = ft_substr(str, 0, len + 1);
	return (s2);
}
// #include <stdio.h>
// int main()
// {
//  char s[]="abchhabc";
//  char d[]="abc";
//  printf("%s\n", ft_strtrim(s, d));

// }