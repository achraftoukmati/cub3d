/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:24:46 by alotfi            #+#    #+#             */
/*   Updated: 2022/11/01 01:45:15 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ft;

	if (!s)
		return (0);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	ft = (char *)malloc(len + 1);
	if (!ft)
		return (0);
	while (s[i] != '\0' && i < len && i < ft_strlen(s))
	{
		ft[i] = s[start];
		i++;
		start++;
	}
	ft[i] = '\0';
	return (ft);
}

// #include <stdio.h>
// int main()
// {
//     char s[]="hola";
//     char b=3;
//     printf("%s\n", ft_substr("hola", 0, 18446744073709551615));
// }