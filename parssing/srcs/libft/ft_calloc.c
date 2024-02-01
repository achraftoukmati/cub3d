/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:54:24 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/31 22:46:54 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cont, size_t size)
{
	char	*p;

	p = malloc(cont * size);
	if (p)
	{
		ft_bzero(p, cont * size);
		return (p);
	}
	return (0);
}
