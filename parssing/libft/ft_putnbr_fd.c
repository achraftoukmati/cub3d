/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:49:29 by alotfi            #+#    #+#             */
/*   Updated: 2022/10/31 23:56:07 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n <= 9 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
// int main()
// {
// 	ft_putnbr_fd(4, 1);
// }