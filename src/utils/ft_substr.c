/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:55:07 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/06 14:16:23 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*substring;

	i = start;
	j = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	while (i < (size_t)ft_strlen(s) && j < len)
	{
		substring[j] = s[i];
		j++;
		i++;
	}
	substring[j] = '\0';
	return (substring);
}
