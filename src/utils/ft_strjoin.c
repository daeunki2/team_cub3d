/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:05:47 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 15:06:44 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	char	*ret;
	int		i;

	i = 0;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * total_length + 1);
	if (!(ret))
		return (NULL);
	while (*s1 != '\0')
	{
		ret[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		ret[i] = *s2;
		i++;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}
