/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:47:29 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/06 14:36:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_game(t_game *info, char *av)
{
	info->file_fd = open(av, O_RDONLY);
	if (info->file_fd < 0)
		return (error_msg("Unable to open the map file."));
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

static void	init_direction(t_game *game)
{
	if (game->player.dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
	}
	else if (game->player.dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
	}
	else if (game->player.dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
	}
	else if (game->player.dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
	}
}

static void	init_plane(t_game *game)
{
	if (game->player.dir == 'N')
	{
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->player.dir == 'S')
	{
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (game->player.dir == 'E')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
	else if (game->player.dir == 'W')
	{
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
}

int	set_map(t_game *game)
{
	dup_map(game);
	if (game->map.grid == NULL)
		return (error_msg("malloc fail set_game"));
	if (surround_wall_check(game, game->map.grid) != 0)
		return (-1);
	set_player_pos(game, game->map.grid);
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.05;
	init_direction(game);
	init_plane(game);
	return (0);
}
