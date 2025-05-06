/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:05:00 by daeunki2          #+#    #+#             */
/*   Updated: 2025/05/06 14:23:12 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	error_msg(char *msg)
{
	printf("Error\n%s\n", msg);
	return (-1);
}

void	free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	parsing_error_out(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.grid)
		free_split(game->map.grid);
	if (game->copied_map)
		free_split(game->copied_map);
	free(game->big_line);
	while (i < 4)
	{
		if (game->textures[i].img && game->mlx)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		if (game->textures[i].path)
			free(game->textures[i].path);
		i++;
	}
	if (game->frame.img && game->mlx)
		mlx_destroy_image(game->mlx, game->frame.img);
	exit(1);
}
