/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:53:45 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 15:15:36 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if ( '0' <= c || c <= '9')
		return (1);
	return (0);
}

int	count_strings(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
