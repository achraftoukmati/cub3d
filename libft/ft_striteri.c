/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:25:15 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/31 21:25:29 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
// int main ()
// {
//     char *r = ft_striteri("ayoub");
//     printf("%s\n", r);
// }