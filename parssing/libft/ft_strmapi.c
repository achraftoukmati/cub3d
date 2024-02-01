/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:49:43 by alotfi            #+#    #+#             */
/*   Updated: 2022/11/03 23:03:29 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fr;

	i = 0;
	fr = malloc(ft_strlen(s) + 1);
	if (!fr)
		return (NULL);
	while (s[i])
	{
		fr[i] = f(i, s[i]);
		i++;
	}
	fr[i] = 0;
	return (fr);
}
// char f(unsigned int x, char  c)
// {
//     return ('y');
// }
// int main ()
// {
//     char *r = ft_strmapi("ayouby", f);
//     printf("%s\n", r);
// }