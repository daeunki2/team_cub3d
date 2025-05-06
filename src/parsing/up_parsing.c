/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:00:56 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/06 19:13:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	up_parsing(t_game *info)
{
	int	i;
	int	type;

	i = 0;
	while (1)
	{
		type = ft_identifi(info->copied_map[i]);
		if (type == T_MAP)
			break ;
		else if (type == T_ERROR)
			return (error_msg("Invalid line in map file"));
		else if (type == T_EA || type == T_SO || type == T_NO || type == T_WE)
		{
			if (direction_path_check(info, i, type) != 0)
				return (-1);
		}
		else if (type == T_CEIL || type == T_FLOOR)
			if (color_parser(info, i, type) != 0)
				return (-1);
		i++;
	}
	if (info_check(info) != 0)
		return (-1);
	return (i);
}

int	info_check(t_game *info)
{
	if (info->textures[T_NO].count != 1)
		return (error_msg("Texture info must appear once above the map"));
	if (info->textures[T_SO].count != 1)
		return (error_msg("Texture info must appear once above the map"));
	if (info->textures[T_EA].count != 1)
		return (error_msg("Texture info must appear once above the map"));
	if (info->textures[T_WE].count != 1)
		return (error_msg("Texture info must appear once above the map"));
	if (info->ceiling_count != 1)
		return (error_msg("Color info must appear once above the map"));
	if (info->floor_count != 1)
		return (error_msg("Color info must appear once above the map"));
	return (0);
}

int	direction_path_check(t_game *info, int k, int nsew)
{
	char	*path_tmp;
	char	*tmp;
	int		fd;

	tmp = ft_strdup(info->copied_map[k]);
	if (!tmp)
		return (error_msg("malloc fail(direction_path_check, 1)"));
	path_tmp = ft_strnstr(tmp, "./", strlen(tmp));
	if (!path_tmp)
		return (error_msg("malloc fail(direction_path_check. 2)"));
	fd = open(path_tmp, O_RDONLY);
	if (fd == -1)
	{
		free(tmp);
		return (error_msg("Can not open file"));
	}
	close(fd);
	info->textures[nsew].type = nsew;
	info->textures[nsew].path = ft_strdup(path_tmp);
	info->textures[nsew].count++;
	free(tmp);
	return (0);
}
