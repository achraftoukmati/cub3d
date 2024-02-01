/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:29:34 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/31 23:15:59 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
//  #include <fcntl.h>
//  int main()
//  {
// 		int fd;
// 		fd = open ("te.txxt", O_RDWR | O_CREAT, 777);
// 		ft_putchar_fd ('5', fd);
//  }