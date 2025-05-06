/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:02:00 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/06 14:23:26 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_wordcount(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
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

char	**ft_split(char *s, char c)
{
	char	**res;
	int		start;
	int		end;
	int		w;

	start = 0;
	end = 0;
	w = 0;
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
