/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:45:55 by alotfi            #+#    #+#             */
/*   Updated: 2024/01/15 06:50:14 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;
	long	nbr;

	nbr = n;
	len = get_len(nbr);
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	len--;
	if (nbr == 0)
		result[0] = 0 + '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[len] = '0' + (nbr % 10);
		nbr = nbr / 10;
		len--;
	}
	return (result);
}
// int main()
// {
//     int n = -747385743;
//     printf("%s\n", ft_itoa(n));
// }