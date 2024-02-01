/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:40:16 by alotfi            #+#    #+#             */
/*   Updated: 2024/01/15 03:38:41 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_join(char *str, char *buffer)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	res = malloc(ft_strlen(str) + ft_strlen(buffer) + 1);
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
		res[i] = str[i];
	while (buffer[j])
		res[i++] = buffer[j++];
	res[i] = '\0';
	free(str);
	return (res);
}
// #include <stdio.h>
// int main()
// {
//     char s1[]="ayoub";
//     char s2[]="lotfi";
//     printf("%s\n", ft_strjoin(s1, s2));
// }