/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:31:43 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 17:54:01 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	color_parser(t_game *info, int i, int type)
{
	char	*tmp;
	int		k;
	int		color;

	k = 0;
	tmp = ft_strdup(info->copied_map[i]);
	if (color_component(tmp) != 0)
		return (-1);
	if (init_color(&color, tmp) != 0)
		return (-1);
	if (type == T_FLOOR)
	{
		info->floor_color = color;
		info->floor_count = info->floor_count + 1;
	}
	if (type == T_CEIL)
	{
		info->ceiling_color = color;
		info->ceiling_count++;
	}
	free(tmp);
	return (0);
}


int	init_color(int *color, char *ptr)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	while (*ptr == ' ' || *ptr == 'F' || *ptr == 'C')
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
		r = r * 10 + (*ptr++ - '0');
	while (*ptr == ' ' || *ptr == ',')
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
		g = g * 10 + (*ptr++ - '0');
	while (*ptr == ' ' || *ptr == ',')
		ptr++;
	while (*ptr >= '0' && *ptr <= '9')
		b = b * 10 + (*ptr++ - '0');
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return(error_msg("0 < color < 255"));
	*color = (r << 16) | (g << 8) | b;
	return(0);
}

int	color_component(char *line)
{
	int	i;
	int	a_count;
	int	d_count;

	i = 0;
	a_count = 0;
	d_count = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr("FC0123456789, \t\n", line[i]) == NULL)
			return (error_msg("불순물 발견"));
		if (line[i] == 'C' || line[i] == 'F')
			a_count++;
		if (line[i] == ',')
			d_count++;
		i++;
	}
	if (a_count != 1 || d_count != 2)
		return(error_msg("color component fail"));
	return (0);
}