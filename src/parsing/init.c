/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:47:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/04 14:24:23 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_game(t_game *info, char *av)
{
	info->file_fd = open(av, O_RDONLY);
	if (info->file_fd < 0)
		return (error_msg("Can not open map file."));
	info->map_h = 0;
	info->map_w = 0;
	info->player_count = 0;
	info->info_count = 0;
	info->ceiling_color = -1;
	info->ceiling_count = 0;
	info->floor_color = -1;
	info->floor_count = 0;
	info->big_line = NULL;
	info->copied_map = NULL;
	set_tile(info);
	return (0);
}
// typedef struct s_img
// {
// 	void	*img;
// 	int		*data;
// 	int		width;
// 	int		height;
// 	char	*path;
// 	int		count;
// 	int		type;
// }	t_img;

void	set_tile(t_game *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		info->textures[i].type = -1;
		info->textures[i].count = 0;
		info->textures[i].path = NULL;
		i++;
	}
}

