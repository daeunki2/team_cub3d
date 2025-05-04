/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:07:14 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 15:10:26 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	read_map(t_game *info)
{
	char	*tmp;
	char	*line;

	info->big_line = ft_strdup("");
	if (info->big_line == NULL)
		return (error_msg("malloc fail(read_map1)"));
	while (1)
	{
		line = get_next_line(info->file_fd);
		if (!line)
			break ;
		tmp = ft_strjoin(info->big_line, line);
		if (!tmp)
		{
			free(line);
			free(info->big_line);
			return (error_msg("strjoin fail(read_map2)"));
		}
		free(info->big_line);
		info->big_line = tmp;
		free(line);
	}
	info->copied_map = ft_split(info->big_line, '\n');
	return (0);
}

int	file_format(char *file)
{
	int		i;
	int		k;
	char	*sample;

	i = 0;
	k = 0;
	sample = ".cub";
	while (file[i] != '.' && file[i] != '\0')
		i++;
	if (file[i] == '\0')
		return (error_msg("file format *.cub"));
	while (file[i] || sample[k])
	{
		if (file[i] != sample[k])
		{
			return (error_msg("file format *.cub"));
		}
		k++;
		i++;
	}
	if (file[i] != '\0')
		return (error_msg("file format *.cub"));
	return (0);
}

// int map_empty(char *big_line)
// {
// 	int i;
// 	int tmp;
	
// 	i = 0;
// 	tmp = 0;
// 	while (big_line[i] != '\0')
// 	{
// 		if (big_line[i] == '\n' && (big_line[i + 1] == ' ' || big_line[i + 1] == '\n'))
// 		{
// 			tmp = i;
// 			while(big_line[i] == '\n' || big_line[i] == ' ')
// 				i++;
// 			if (ft_strchr("01NSEW ", big_line[tmp - 1]) != NULL && ft_strchr("01NSEW ", big_line[i]) != NULL)
// 				return(error_msg("no empty line in map"));
// 		}
// 		tmp = 0;
// 		i++;
// 	}
// 	return (0);
// }
