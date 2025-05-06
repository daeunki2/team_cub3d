/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:48:30 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/06 14:15:59 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	*ft_memset(void *pointeur, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)pointeur)[i] = value;
		i++;
	}
	return (pointeur);
}
