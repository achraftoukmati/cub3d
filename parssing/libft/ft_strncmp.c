/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:29:25 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/31 22:18:24 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     char s1[]="teyst";
//     char s2[]="tekst";
//     char s3[]="teyst";
//     char s4[]="tekst";

//     printf("%d\n",ft_strncmp(s1, s2 , 7));
//     printf("%d\n",strncmp(s3, s4 , 7));
// }