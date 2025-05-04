/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:04:50 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 18:32:16 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_parsing(t_game *info, char *av)
{
	int	last;
	int	start;

	info->file_fd = open(av, O_RDONLY);
	if (info->file_fd < 0)
		return (error_msg("Can not open map file."));// check fd.
	if (file_format(av) != 0)// file format check
		return(-1);
	set_game(info, av);
	if (read_map(info) != 0)// read file and store 
		return (error_msg("Can not open map file."));
	start = up_parsing(info);// check textuer color info, retrun start line of map.
	if (start == -1)
		return (-1);
	last = down_parsing(info, start);// check map
	if (last == -1)
		return (-1);
	info->map_h = last - start;
	info->map.height = info->map_h;
	info->map.width = info->map_w;
	return (0);
}

int	ft_identifi(char *str)
{
	int	flag;

	if (!str)
		return (T_ERROR);
	if (ft_strncmp(str, "NO ", 3) == 0)
		return (T_NO);
	if (ft_strncmp(str, "SO ", 3) == 0)
		return (T_SO);
	if (ft_strncmp(str, "WE ", 3) == 0)
		return (T_WE);
	if (ft_strncmp(str, "EA ", 3) == 0)
		return (T_EA);
	if (ft_strncmp(str, "F ", 2) == 0)
		return (T_FLOOR);
	if (ft_strncmp(str, "C ", 2) == 0)
		return (T_CEIL);
	flag = is_map_line(str);
	if (flag == T_MAP)
		return (T_MAP);
	else if (flag == T_EMPTY)
		return (T_EMPTY);
	else if (flag == T_ERROR)
		return (T_ERROR);
	return (T_ERROR);
}
