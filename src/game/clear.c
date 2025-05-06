/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:22:44 by rgrochow          #+#    #+#             */
/*   Updated: 2025/05/06 14:21:09 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clear_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.grid)
	{
		while (game->map.grid[i])
			free(game->map.grid[i++]);
		free(game->map.grid);
	}
	parsing_free(game);
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		if (game->textures[i].path)
			free(game->textures[i].path);
		i++;
	}
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		(mlx_destroy_display(game->mlx), free(game->mlx));
}

void	parsing_free(t_game *game)
{
	if (game->copied_map)
		free_split(game->copied_map);
	free(game->big_line);
}
