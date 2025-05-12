/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:13:50 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/06 14:35:48 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	down_parsing(t_game *info, int start)
{
	int	width;
	int	flag;

	info->map_start = start;
	flag = ft_identifi(info->copied_map[start]);
	while (info->copied_map[start] != NULL)
	{
		if (flag != T_MAP)
		{
			if (is_end_map(info, start) != 0)
				return (-1);
			break ;
		}
		width = component_check(info, info->copied_map[start]);
		if (width == -1)
			return (-1);
		if (info->player_count > 1)
			return (error_msg("There must be only one player"));
		if (width > info->map_w)
			info->map_w = width;
		start++;
		flag = ft_identifi(info->copied_map[start]);
	}
	return (start);
}

int	component_check(t_game *info, char *map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i] != '\0')
	{
		if (ft_strchr("01NESW \n", map[i]) == NULL)
		{
			k = ft_identifi(map);
			if (T_NO <= k && k <= T_CEIL)
				return (error_msg("Map must appear at the end of the file"));
			return (error_msg("Invalid character in map"));
		}
		if (map[i] == 'N')
			info->player_count++;
		if (map[i] == 'S')
			info->player_count++;
		if (map[i] == 'E')
			info->player_count++;
		if (map[i] == 'W')
			info->player_count++;
		i++;
	}
	return (i);
}

int	is_map_line(char *str)
{
	int	k;
	int	space;

	k = 0;
	space = 0;
	while (str[k] != '\0')
	{
		if (ft_strchr("01NESW \n", str[k]) == NULL)
			return (T_ERROR);
		if (str[k] == ' ')
			space++;
		k++;
	}
	if (str[k] == '\0' && space == k)
		return (T_EMPTY);
	return (T_MAP);
}

int	is_end_map(t_game *info, int i)
{
	int	flag;
	int	k;

	k = i + 1;
	while (info->copied_map[k] != NULL)
	{
		flag = ft_identifi(info->copied_map[k]);
		if (T_NO <= flag && flag <= T_CEIL)
			return (error_msg("Map must appear at the end of the file"));
		else if (flag == T_MAP)
			return (error_msg("Empty lines are not allowed in the map"));
		k++;
	}
	return (0);
}
