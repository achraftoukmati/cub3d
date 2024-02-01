/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alotfi <alotfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 22:17:00 by alotfi            #+#    #+#             */
/*   Updated: 2024/01/17 16:19:42 by alotfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_cont(char *s, char c, char w)
{
	size_t count;

	count = 0;
	while (*s)
	{
		while (*s == c || *s == w)
			s++;
		if (*s)
			count++;
		while (*s && *s != c && *s != w)
			s++;
	}
	return (count);
}

char	**ft_split(char *s, char c, char w)
{
	char	**sp;
	size_t	start;
	size_t	end;
	size_t	i;

	sp = (char **)malloc((my_cont(s, c, w) + 1) * sizeof(char *));
	if (!sp)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (i < my_cont(s, c, w))
	{
		while (s[start] == c || s[start] == w)
			start++;
		end = start;
		while (s[end] != c && s[end] != w && s[end])
			end++;
		sp[i] = ft_substr(s, start, end - start);
		start = end;
		i++;
	}
	sp[i] = NULL;
	return (sp);
}

// int	my_cont(char *s, char c)
// {
// 	size_t	i;
// 	int		word;
// 	int		found;

// 	found = 0;
// 	i = 0;
// 	word = 0;
// 	while (i <= ft_strlen(s))
// 	{
// 		if ((s[i] == c || s[i] == '\0') && found)
// 		{
// 			word++;
// 			found = 0;
// 		}
// 		if (s[i] != c && !found)
// 			found = 1;
// 		i++;
// 	}
// 	return (word);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**sp;
// 	size_t	start;
// 	size_t	end;
// 	size_t	i;

// 	sp = (char **)malloc((my_cont((char *)s, c) + 1) * (sizeof(char *)));
// 	if (!sp)
// 		return (NULL);
// 	start = 0;
// 	end = 0;
// 	i = 0;
// 	while ((int)i < my_cont((char *)s, c))
// 	{
// 		while (s[start] == c)
// 			start++;
// 		end = start;
// 		while (s[end] != c && s[end])
// 			end++;
// 		sp[i] = ft_substr(s, start, (end - start));
// 		start = end;
// 		i++;
// 	}
// 	sp[i] = NULL;
// 	return (sp);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	int	i;
// 	// char	**words;

//     i = 0 ;
//     char s[]="   hello adkls world   askljfasj ";
// 	int words = my_cont(s, 0);
// 	printf("%d\n", words);
//     // words = ft_split(s, 0);
// 	// while (*words)
// 	// {
// 	// 	printf("%s\n", *words);
// 	// 	words++;
// 	// }
// }
