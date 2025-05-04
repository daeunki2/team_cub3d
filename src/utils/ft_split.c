/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:02:00 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 15:43:21 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	ft_wordcount(char *str, char sep)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	if (ft_strlen(str) == 0)
// 		return (0);
// 	if (str[0] == sep)
// 		count = 0;
// 	else
// 		count = 1;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == sep && str[i + 1] != '\0' && str[i + 1] != sep)
// 		{
// 			count++;
// 			i++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }
int	ft_wordcount(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 1; // 최소한 한 단어 존재
	while (str[i])
	{
		if (str[i] == sep)
			count++;
		i++;
	}
	return (count);
}

int	ft_wordlen(char *substr, char sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (substr[i] != '\0' && substr[i] != sep)
	{
		i++;
		len++;
	}
	return (len);
}

int	ft_issep(char *s, char c)
{
	if (*s == c)
		return (1);
	else
		return (0);
}

// char	**ft_split(char *s, char c)
// {
// 	char	**res;
// 	int		w;
// 	char	*s2;

// 	w = 0;
// 	s2 = (char *)s;
// 	if (s2 == NULL)
// 		return (NULL);
// 	res = malloc(sizeof(char *) * (ft_wordcount(s2, c) + 1));
// 	if (res == NULL)
// 		return (NULL);
// 	while (*s2)
// 	{
// 		if (*s2 && ft_issep (s2, c) == 0)
// 		{
// 			res[w++] = ft_substr(s2, 0, ft_wordlen(s2, c));
// 			s2 += ft_wordlen(s2, c);
// 		}
// 		while (*s2 && ft_issep (s2, c) == 1)
// 		{
// 			s2++;
// 		}
// 	}
// 	res[w] = 0;
// 	return (res);
// }
char	**ft_split(char *s, char c)
{
	char	**res;
	int		start = 0;
	int		end = 0;
	int		w = 0;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[end])
	{
		if (s[end] == c)
		{
			res[w++] = ft_substr(s, start, end - start);
			start = end + 1;
		}
		end++;
	}
	res[w++] = ft_substr(s, start, end - start);
	res[w] = 0;
	return (res);
}

