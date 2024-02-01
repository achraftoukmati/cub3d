/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:08:50 by alotfi            #+#    #+#             */
/*   Updated: 2024/01/17 16:20:09 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strrchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_str_join(char *str, char *buffer);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char *sr, char c, char w);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_calloc(size_t cont, size_t size);
void	ft_putchar_fd(char n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

#endif